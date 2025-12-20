#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return 1/(1+x*x);
}

int main(){
    freopen("input/input_simpson1of3.txt", "r", stdin);
    freopen("output/output_simpson1of3.txt", "w", stdout);
    
    double a, b;
    int n;
    
    cin>>a>>b>>n;
    
    if(n <= 0){
        cout << "Error: n must be positive!" << endl;
        return 1;
    }
    
    if(n % 2 != 0){
        cout << "Error: n must be even!" << endl;
        return 1;
    }
    
    double h = (b - a) / n;
    
    // Simpson's 1/3 Rule: I = (h/3)[f(a) + 4*Σf(odd) + 2*Σf(even) + f(b)]
    double sum = f(a) + f(b);
    
    for(int i = 1; i < n; i++){
        double x = a + i * h;
        if(i % 2 == 0){
            sum += 2 * f(x);  // Even terms
        } else {
            sum += 4 * f(x);  // Odd terms
        }
    }
    
    double result = (h / 3.0) * sum;
    
    cout << "\n========== SIMPSON'S 1/3 RULE RESULT ==========" << endl;
    cout << fixed << setprecision(6);
    cout << "Lower limit (a): " << a << endl;
    cout << "Upper limit (b): " << b << endl;
    cout << "Number of subintervals (n): " << n << endl;
    cout << "Step size (h): " << h << endl;
    cout << "\nIntegral value: " << result << endl;
    
    return 0;
}