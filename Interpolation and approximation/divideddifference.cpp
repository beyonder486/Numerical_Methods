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
    
    // ========== ERROR CALCULATION ==========
    char calcError;
    cout << "\nDo you want to calculate error? (y/n): ";
    cin >> calcError;
    
    if(calcError == 'y' || calcError == 'Y'){
        cout << "\n=== ERROR CALCULATION OPTIONS ===" << endl;
        cout << "1. Compare with actual value" << endl;
        cout << "2. Use additional data point" << endl;
        cout << "3. Truncation error estimate" << endl;
        cout << "Choose option (1/2/3): ";
        
        int option;
        cin >> option;
        
        if(option == 1){
            // Option 1: Compare with actual value
            double actualValue;
            cout << "Enter the actual/true value at x = " << xp << ": ";
            cin >> actualValue;
            
            double absoluteError = fabs(actualValue - result);
            double relativeError = fabs(absoluteError / actualValue);
            double percentageError = relativeError * 100.0;
            
            cout << "\n========== ERROR ANALYSIS ==========" << endl;
            cout << "Actual Value       : " << fixed << setprecision(6) << actualValue << endl;
            cout << "Interpolated Value : " << result << endl;
            cout << "Absolute Error     : " << absoluteError << endl;
            cout << "Relative Error     : " << relativeError << endl;
            cout << "Percentage Error   : " << percentageError << "%" << endl;
        }
        else if(option == 2){
            // Option 2: Use additional data point
            cout << "Enter additional data point (x y): ";
            double x_new, y_new;
            cin >> x_new >> y_new;
            
            // Calculate with n points
            vector<vector<double>> dd_old(n, vector<double>(n, 0));
            double result_without = dividedDifference(x, y, n, xp, dd_old);
            
            // Add new point
            vector<double> x_extended(n+1), y_extended(n+1);
            for(int i = 0; i < n; i++){
                x_extended[i] = x[i];
                y_extended[i] = y[i];
            }
            x_extended[n] = x_new;
            y_extended[n] = y_new;
            
            // Calculate with n+1 points
            vector<vector<double>> dd_new(n+1, vector<double>(n+1, 0));
            double result_with = dividedDifference(x_extended, y_extended, n+1, xp, dd_new);
            
            cout << "\n========== ERROR ANALYSIS ==========" << endl;
            cout << "Result WITHOUT additional point: " << fixed << setprecision(6) << result_without << endl;
            cout << "Result WITH additional point:    " << result_with << endl;
            
            double absoluteError = fabs(result_with - result_without);
            double relativeError = fabs(absoluteError / result_with);
            double percentageError = relativeError * 100.0;
            
            cout << "Absolute Error     : " << absoluteError << endl;
            cout << "Relative Error     : " << relativeError << endl;
            cout << "Percentage Error   : " << percentageError << "%" << endl;
            
            cout << "\nInterpretation: The error of " << absoluteError << " represents" << endl;
            cout << "the contribution of the (n+1)th term in Newton's formula." << endl;
        }
        else if(option == 3){
            // Option 3: Truncation error estimate
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
        }
    }
    
    return 0;
}