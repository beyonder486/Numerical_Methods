#include<bits/stdc++.h>
using namespace std;

double f(double x){
    // Define your function here
    return 1/(1+x*x);  // Example: sin(x)
}

int main(){
    double a, b;
    int n;
    
    cout << "Enter lower limit a: ";
    cin >> a;
    cout << "Enter upper limit b: ";
    cin >> b;
    cout << "Enter number of subintervals n (must be even): ";
    cin >> n;
    
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
    
    cout << fixed << setprecision(6);
    cout << "Integral = " << result << endl;
    
    return 0;
}