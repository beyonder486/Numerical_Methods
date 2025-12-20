#include<bits/stdc++.h>
using namespace std;

double dividedDifference(vector<double>& x, vector<double>& y, int n, double xp, vector<vector<double>>& dd){
    // Create divided difference table
    for(int i = 0; i < n; i++){
        dd[i][0] = y[i];
    }
    
    for(int j = 1; j < n; j++){
        for(int i = 0; i < n - j; i++){
            dd[i][j] = (dd[i+1][j-1] - dd[i][j-1]) / (x[i+j] - x[i]);
        }
    }
    
    // Newton's Divided Difference Formula
    double result = dd[0][0];
    double prod = 1.0;
    
    for(int i = 1; i < n; i++){
        prod *= (xp - x[i-1]);
        result += prod * dd[0][i];
    }
    
    return result;
}

int main(){
    freopen("input/input_divideddifference.txt", "r", stdin);
    freopen("output/output_divideddifference.txt", "w", stdout);
    
    int n;
    cout << "Enter number of data points: ";
    cin >> n;
    
    vector<double> x(n), y(n);
    
    cout << "Enter data points (x y):" << endl;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    
    // Create divided difference table
    vector<vector<double>> dd(n, vector<double>(n, 0));
    
    for(int i = 0; i < n; i++){
        dd[i][0] = y[i];
    }
    
    // Calculate divided differences
    for(int j = 1; j < n; j++){
        for(int i = 0; i < n - j; i++){
            dd[i][j] = (dd[i+1][j-1] - dd[i][j-1]) / (x[i+j] - x[i]);
        }
    }
    
    // Display divided difference table
    cout << "\nDivided Difference Table:" << endl;
    cout << setw(10) << "x" << setw(12) << "f(x)";
    for(int j = 1; j < n; j++){
        cout << setw(15) << "f[x" << j << "]";
    }
    cout << endl;
    cout << string(10 + 15*n, '-') << endl;
    
    for(int i = 0; i < n; i++){
        cout << fixed << setprecision(4);
        cout << setw(10) << x[i];
        for(int j = 0; j < n - i; j++){
            cout << setw(15) << dd[i][j];
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
    
    // Newton's Divided Difference Formula
    double result = dd[0][0];
    double prod = 1.0;
    
    cout << "\nCalculation steps:" << endl;
    cout << "y(" << xp << ") = " << dd[0][0];
    
    for(int i = 1; i < n; i++){
        prod *= (xp - x[i-1]);
        double term = prod * dd[0][i];
        result += term;
        
        cout << " + ";
        for(int k = 0; k < i; k++){
            cout << "(x-" << x[k] << ")";
        }
        cout << " * " << dd[0][i];
    }
    
    cout << endl;
    cout << "\n========== RESULT ==========" << endl;
    cout << "y(" << xp << ") = " << fixed << setprecision(6) << result << endl;
    
    // ========== AUTOMATIC TRUNCATION ERROR ESTIMATE ==========
    cout << "\n========== TRUNCATION ERROR ESTIMATE ==========" << endl;
    
    // Calculate term-by-term contribution
    cout << "\nTerm-by-term contributions:" << endl;
    double cumulative = dd[0][0];
    cout << "Term 0: " << fixed << setprecision(6) << cumulative << endl;
    
    prod = 1.0;
    for(int i = 1; i < n; i++){
        prod *= (xp - x[i-1]);
        double term = prod * dd[0][i];
        cumulative += term;
        cout << "Term " << i << ": " << term << " (cumulative: " << cumulative << ")" << endl;
    }
    
    // Estimate next term (if we had n+1 points)
    prod *= (xp - x[n-1]);
    double estimated_next_term = fabs(prod * dd[0][n-1]);
    
    cout << "\nEstimated truncation error (next term magnitude):" << endl;
    cout << "≈ |(x-x0)(x-x1)...(x-x" << n-1 << ")| * |f[x0,...,x" << n-1 << "]|" << endl;
    cout << "≈ " << estimated_next_term << endl;
    
    cout << "\nNote: This is an approximation. Actual error depends on" << endl;
    cout << "the (n+1)th divided difference which is unknown." << endl;
    
    // Show relative magnitude of last term
    double last_term = fabs(prod / (xp - x[n-2]) * dd[0][n-1]);
    cout << "\nLast term used: " << last_term << endl;
    cout << "As percentage of result: " << (last_term/fabs(result))*100 << "%" << endl;
    
    return 0;
}