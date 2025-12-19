#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return 2*x*x-9*x+2;
}

int main(){
    freopen("input_regularfalsi.txt", "r", stdin);
    freopen("output_regularfalsi.txt", "w", stdout);
    
    double a, b, tolerance;
    int maxIterations;
    cin >> a >> b >> tolerance >> maxIterations;
    
    double lim=0;
    while(f(a)*f(b)>0 && lim<maxIterations){
        b++;
        lim++;
    }
    
    if(f(a)*f(b)>0){
        cout << "Error: Could not find interval with sign change!" << endl;
        return 1;
    }
    
    double c=a-f(a)*(b-a)/(f(b)-f(a));
    int it=0;
    while(fabs(f(c))>tolerance && it<maxIterations){
        if(f(a)*f(c)<0)b=c;
        else a=c;
        
        double denom = f(b)-f(a);
        if(fabs(denom) < 1e-10){
            break; // Converged 
        }
        c=a-f(a)*(b-a)/denom;
        it++;
    }
    
    cout << "\n========== REGULAR FALSI (FALSE POSITION) METHOD RESULT ==========" << endl;
    cout << "Root: " << fixed << setprecision(10) << c << endl;
    cout << "Iterations: " << it << endl;
    cout << "f(" << c << ") = " << scientific << f(c) << endl;
    cout << "Tolerance: " << fixed << tolerance << endl;

    return 0;
}