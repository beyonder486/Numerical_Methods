#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return 2*x*x-9*x+2;
}

int main(){
    freopen("input_bisection.txt", "r", stdin);
    freopen("output_bisection.txt", "w", stdout);
    
    double a, b, tolerance;
    int maxIterations;
    cin >> a >> b >> tolerance >> maxIterations;
    
    double limit=0;
    double res=0,r=0;
    bool tf1=false,tf2=false;
    if(fabs(f(a))<tolerance){
        tf1=true;
        res=a;
    }
    while(f(a)*f(b)>0 && limit<maxIterations){
        if(fabs(f(b))<tolerance){
            tf2=true;
            r=b;
        }
        b++;
        limit++;
    }
    
    if(f(a)*f(b)>0){
        cout << "Error: Could not find interval with sign change!" << endl;
        if(tf1) cout << res << endl;
        if(tf2) cout << r << endl;
        return 1;
    }
    
    double c=(a+b)/2;
    int i=0;
    while(fabs(f(c))>tolerance && i<maxIterations){
        if(f(a)*f(c)<0)b=c;
        else a=c;
        c=(a+b)/2;
        i++;
    }
    
    cout << "\n========== BISECTION METHOD RESULT ==========" << endl;
    if(tf1){
        cout << "Root found at: " << fixed << setprecision(10) << res << endl;
    }
    if(tf2){
        cout << "Root found at: " << fixed << setprecision(10) << r << endl;
    }
    cout << "Root: " << fixed << setprecision(10) << c << endl;
    cout << "Iterations: " << i << endl;
    cout << "f(" << c << ") = " << scientific << f(c) << endl;

    return 0;
}