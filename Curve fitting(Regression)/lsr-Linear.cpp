#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input/input_lsr_Linear.txt", "r", stdin);
    freopen("output/output_lsr_Linear.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<double> x(n), y(n);
    
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    
    // Display input data
    cout << "\nData Points:" << endl;
    cout << setw(10) << "x" << setw(10) << "y" << endl;
    cout << string(20, '-') << endl;
    for(int i = 0; i < n; i++){
        cout << setw(10) << x[i] << setw(10) << y[i] << endl;
    }
    
    // Calculate sums needed for least squares
    double sum_x = 0, sum_y = 0;
    double sum_x2 = 0, sum_xy = 0;
    
    for(int i = 0; i < n; i++){
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }
    
    cout << "\n========== CALCULATIONS ==========" << endl;
    cout << "Σx   = " << sum_x << endl;
    cout << "Σy   = " << sum_y << endl;
    cout << "Σx²  = " << sum_x2 << endl;
    cout << "Σxy  = " << sum_xy << endl;
    cout << "n    = " << n << endl;
    
    // Least Squares Formulas:
    // y = ax + b
    // a = (n*Σxy - Σx*Σy) / (n*Σx² - (Σx)²)
    // b = (Σy - a*Σx) / n
    
    double denominator = n * sum_x2 - sum_x * sum_x;
    
    if(fabs(denominator) < 1e-10){
        cout << "\nError: Cannot fit a line (denominator is zero)" << endl;
        cout << "Data points may be vertical or duplicate." << endl;
        return 1;
    }
    
    double a = (n * sum_xy - sum_x * sum_y) / denominator;
    double b = (sum_y - a * sum_x) / n;
    
    cout << "\n========== LEAST SQUARES LINEAR REGRESSION ==========" << endl;
    cout << "Best fit line: y = " << fixed << setprecision(4) << a << "x";
    if(b >= 0){
        cout << " + " << b << endl;
    } else {
        cout << " - " << fabs(b) << endl;
    }
    
    // Calculate R² (coefficient of determination)
    double mean_y = sum_y / n;
    double ss_tot = 0;  // Total sum of squares
    double ss_res = 0;  // Residual sum of squares
    
    for(int i = 0; i < n; i++){
        double y_fitted = a * x[i] + b;
        double residual = y[i] - y_fitted;
        
        ss_res += residual * residual;
        ss_tot += (y[i] - mean_y) * (y[i] - mean_y);
    }
    
    double r_squared = 1 - (ss_res / ss_tot);
    double correlation = sqrt(r_squared);
    if(a < 0) correlation = -correlation;  // Negative correlation if slope is negative
    
    cout << "\n========== GOODNESS OF FIT ==========" << endl;
    cout << "R² (Coefficient of Determination): " << r_squared << endl;
    cout << "Correlation Coefficient (r):       " << correlation << endl;
    
    if(r_squared > 0.9){
        cout << "Interpretation: Excellent fit (R² > 0.9)" << endl;
    } else if(r_squared > 0.7){
        cout << "Interpretation: Good fit (R² > 0.7)" << endl;
    } else if(r_squared > 0.5){
        cout << "Interpretation: Moderate fit (R² > 0.5)" << endl;
    } else {
        cout << "Interpretation: Poor fit (R² < 0.5)" << endl;
    }
    
    return 0;
}