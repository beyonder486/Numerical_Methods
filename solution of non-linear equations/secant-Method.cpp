#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return x*x*x*x-3*x*x+1;
}
// double df(double x){
//     return 4*x*x*x-6*x;
// }
double calc(double x,double y){
    double denom = f(x)-f(y);
    if(fabs(denom) < 1e-10){
        return x; // Return current value if denominator is zero
    }
    return x-f(x)*(x-y)/denom;
}
int main(){
    freopen("input_secant.txt", "r", stdin);
    freopen("output_secant.txt", "w", stdout);
    
    double a, b, step, tolerance;
    int maxIterations;
    cin >> a >> b >> step >> tolerance >> maxIterations;
    
    double c=0;
    vector<pair<double,double>>p;
    for(double i=a;i<b;i+=step){
        if(f(i)*f(i+step)<0){
            p.push_back({i,i+step});
            i+=0.5;
        }
    }
    int n=p.size(),i=0,j=0;
    
    if(n == 0){
        cout << "No roots found in the given interval!" << endl;
        return 0;
    }
    
    cout << "\n========== SECANT METHOD RESULTS ==========" << endl;
    cout << "Number of roots found: " << n << endl;
    cout << "\nRoots:" << endl;
    
    int rootNum = 1;
    while(n--){
        double x1=p[i].second;
        double x0=p[i].first;
        c=(x0+x1)/2;
        int iterCount = 0;
        while(fabs(f(c))>tolerance && iterCount<maxIterations){
            c=calc(x1,x0);
            x0=x1;
            x1=c;
            iterCount++;
            j++;
        }
        cout << "Root " << rootNum++ << ": " << fixed << setprecision(10) << c << " (iterations: " << iterCount << ")" << endl;
        i++;
    }
    cout << "\nTotal iterations across all roots: " << j << endl;
    return 0;
}