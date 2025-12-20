#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input/input_forwardinterpolation.txt", "r", stdin);
    freopen("output/output_forwardinterpolation.txt", "w", stdout);
    
    int n;
    cout << "Enter number of class intervals: ";
    cin >> n;
    
    vector<double> lowerBound(n), upperBound(n), y(n), x(n);
    
    cout << "Enter class intervals and frequencies:" << endl;
    cout << "(Format: lower upper frequency)" << endl;
    for(int i = 0; i < n; i++){
        cin >> lowerBound[i] >> upperBound[i] >> y[i];
        // Calculate class midpoint (class mark)
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
    
    // Check if x values (midpoints) are equally spaced
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
    
    // Create forward difference table
    vector<vector<double>> diff(n, vector<double>(n));
    
    // First column is y values
    for(int i = 0; i < n; i++){
        diff[i][0] = y[i];
    }
    
    // Calculate forward differences
    for(int j = 1; j < n; j++){
        for(int i = 0; i < n - j; i++){
            diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
        }
    }
    
    // Display forward difference table
    cout << "\nForward Difference Table:" << endl;
    cout << setw(10) << "x" << setw(12) << "y";
    for(int j = 1; j < n; j++){
        cout << setw(12) << "Δ^" << j << "y";
    }
    cout << endl;
    cout << string(10 + 12*n, '-') << endl;
    
    for(int i = 0; i < n; i++){
        cout << fixed << setprecision(4);
        cout << setw(10) << x[i];
        for(int j = 0; j < n - i; j++){
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
    
    // Calculate p (normalized variable)
    double p = (xp - x[0]) / h;
    
    cout << "\np = (x - x0) / h = (" << xp << " - " << x[0] << ") / " << h << " = " << p << endl;
    
    // Newton's Forward Interpolation Formula
    double result = diff[0][0];  // y0
    double pTerm = p;
    double factorial = 1;
    
    cout << "\nCalculation steps:" << endl;
    cout << "y(" << xp << ") = " << diff[0][0];
    
    for(int j = 1; j < n; j++){
        // Calculate p(p-1)(p-2)...(p-j+1)
        if(j > 1){
            pTerm *= (p - (j - 1));
        }
        
        factorial *= j;
        
        double term = (pTerm / factorial) * diff[0][j];
        result += term;
    }
    
    cout << endl;
    cout << "\n========== RESULT ==========" << endl;
    cout << "y(" << xp << ") = " << fixed << setprecision(6) << result << endl;
    
    return 0;
}