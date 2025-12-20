#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input/input_backwardinterpolation.txt", "r", stdin);
    freopen("output/output_backwardinterpolation.txt", "w", stdout);
    
    int n;
    cout << "Enter number of class intervals: ";
    cin >> n;
    
    vector<double> lowerBound(n), upperBound(n), y(n), x(n);
    
    cout << "Enter class intervals and frequencies:" << endl;
    cout << "(Format: lower upper frequency)" << endl;
    for(int i = 0; i < n; i++){
        cin >> lowerBound[i] >> upperBound[i] >> y[i];
        x[i] = (lowerBound[i] + upperBound[i]) / 2.0;
    }
    
    // Display input data
    cout << "\nClass Intervals and Midpoints:" << endl;
    cout << setw(15) << "Interval" << setw(15) << "Midpoint(x)" << setw(15) << "Frequency(y)" << endl;
    cout << string(45, '-') << endl;
    for(int i = 0; i < n; i++){
        cout << setw(7) << lowerBound[i] << "-" << setw(7) << upperBound[i] 
             << setw(15) << x[i] << setw(15) << y[i] << endl;
    }
    
    // Check if x values are equally spaced
    double h = x[1] - x[0];
    bool equallySpaced = true;
    for(int i = 1; i < n-1; i++){
        if(fabs((x[i+1] - x[i]) - h) > 1e-6){
            equallySpaced = false;
            break;
        }
    }
    
    if(!equallySpaced){
        cout << "Error: Class intervals must be equally spaced!" << endl;
        return 1;
    }
    
    cout << "\nClass width (h) = " << h << endl;
    
    // Create BACKWARD difference table
    vector<vector<double>> diff(n, vector<double>(n));
    
    // First column is y values
    for(int i = 0; i < n; i++){
        diff[i][0] = y[i];
    }
    
    // Calculate BACKWARD differences
    // ∇y[i] = y[i] - y[i-1]
    for(int j = 1; j < n; j++){
        for(int i = n-1; i >= j; i--){  // ✅ Start from bottom, go upward
            diff[i][j] = diff[i][j-1] - diff[i-1][j-1];
        }
    }
    
    // Display backward difference table
    cout << "\nBackward Difference Table:" << endl;
    cout << setw(10) << "x" << setw(12) << "y";
    for(int j = 1; j < n; j++){
        cout << setw(12) << "∇^" << j << "y";
    }
    cout << endl;
    cout << string(10 + 12*n, '-') << endl;
    
    for(int i = 0; i < n; i++){
        cout << fixed << setprecision(4);
        cout << setw(10) << x[i];
        for(int j = 0; j <= i && j < n; j++){  // ✅ Print only valid entries
            cout << setw(12) << diff[i][j];
        }
        cout << endl;
    }
    
    // Input value to interpolate
    double xp;
    cout << "\nEnter value of x to interpolate: ";
    cin >> xp;
    
    // Check if xp is within range
    if(xp < x[0] || xp > x[n-1]){
        cout << "Warning: Extrapolating outside data range!" << endl;
    }
    
    // Calculate q (normalized variable from END)
    // ✅ Use xₙ (last point) as reference
    double q = (xp - x[n-1]) / h;
    
    cout << "\nq = (x - xn) / h = (" << xp << " - " << x[n-1] << ") / " << h << " = " << q << endl;
    
    // Newton's Backward Interpolation Formula
    // y(x) = yₙ + q∇yₙ + q(q+1)/2! ∇²yₙ + q(q+1)(q+2)/3! ∇³yₙ + ...
    
    double result = diff[n-1][0];  // ✅ Start with yₙ (last y value)
    double qTerm = q;
    double factorial = 1;
    
    cout << "\nCalculation steps:" << endl;
    cout << "y(" << xp << ") = " << diff[n-1][0];
    
    for(int j = 1; j < n; j++){
        // Calculate q(q+1)(q+2)...(q+j-1)
        // ✅ Note: (q+1), (q+2), ... instead of (q-1), (q-2), ...
        if(j > 1){
            qTerm *= (q + (j - 1));
        }
        
        factorial *= j;
        
        double term = (qTerm / factorial) * diff[n-1][j];  // ✅ Use diff[n-1][j] (last row)
        result += term;
    }
    
    cout << endl;
    cout << "\n========== RESULT ==========" << endl;
    cout << "y(" << xp << ") = " << fixed << setprecision(6) << result << endl;
    
    return 0;
}