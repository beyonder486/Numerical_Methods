#include<bits/stdc++.h>
using namespace std;

double f(double x){
    // Define your function here
    return sin(x);  // Example: sin(x)
}

int main(){
    freopen("input_simpson3of8.txt", "r", stdin);
    freopen("output_simpson3of8.txt", "w", stdout);
    
    double a, b;
    int n;
    
    cin >> a>>b>>n;
    
    if(n <= 0){
        cout << "Error: n must be positive!" << endl;
        return 1;
    }
    
    if(n % 3 != 0){
        cout << "Error: n must be a multiple of 3!" << endl;
        return 1;
    }
    
    double h = (b - a) / n;
    
    // Simpson's 3/8 Rule: I = (3h/8)[f(a) + 3*Σf(x1,x2,x4,x5...) + 2*Σf(x3,x6...) + f(b)]
    double sum = f(a) + f(b);
    
    for(int i = 1; i < n; i++){
        double x = a + i * h;
        if(i % 3 == 0){
            sum += 2 * f(x);  // Multiples of 3
        } else {
            sum += 3 * f(x);  // Non-multiples of 3
        }
    }
    
    double result = (3 * h / 8.0) * sum;
    
    cout << "\n========== SIMPSON'S 3/8 RULE RESULT ==========" << endl;
    cout << fixed << setprecision(6);
    cout << "Lower limit (a): " << a << endl;
    cout << "Upper limit (b): " << b << endl;
    cout << "Number of subintervals (n): " << n << endl;
    cout << "Step size (h): " << h << endl;
    cout << "\nIntegral value: " << result << endl;
    
    return 0;
}