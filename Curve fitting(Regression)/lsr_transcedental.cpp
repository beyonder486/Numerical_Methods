#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input/input_lsr_transcedental.txt", "r", stdin);
    freopen("output/output_lsr_transcedental.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    if(n < 2){
        cout << "Error: Need at least 2 data points!" << endl;
        return 1;
    }
    
    vector<double> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        if(y[i] <= 0){
            cout << "Error: All y values must be positive for exponential fit!" << endl;
            return 1;
        }
    }
    
    // For y = a*e^(bx), transform to ln(y) = ln(a) + bx
    vector<double> Y(n);
    for(int i = 0; i < n; i++){
        Y[i] = log(y[i]);
    }
    
    double sx = 0, sY = 0, sx2 = 0, sxY = 0;
    for(int i = 0; i < n; i++){
        sx += x[i];
        sY += Y[i];
        sx2 += x[i] * x[i];
        sxY += x[i] * Y[i];
    }
    
    double denom = n * sx2 - sx * sx;
    if(fabs(denom) < 1e-10){
        cout << "Error: Cannot fit exponential curve (singular matrix)!" << endl;
        return 1;
    }
    
    double b = (n * sxY - sx * sY) / denom;
    double A = (sY - b * sx) / n;
    double a = exp(A);
    
    cout << "\n========== EXPONENTIAL LEAST SQUARES REGRESSION ==========" << endl;
    cout << "Number of data points: " << n << endl;
    cout << "\nBest fit exponential equation:" << endl;
    cout << "y = " << fixed << setprecision(6) << a << " * e^(" << b << "x)" << endl;
    
    return 0;
}