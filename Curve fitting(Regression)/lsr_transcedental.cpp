#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<double> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
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
    
    double b = (n * sxY - sx * sY) / (n * sx2 - sx * sx);
    double A = (sY - b * sx) / n;
    double a = exp(A);
    
    cout << "y = " << a << " * e^(" << b << "x)" << endl;
    
    return 0;
}