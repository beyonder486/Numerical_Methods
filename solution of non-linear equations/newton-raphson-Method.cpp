#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return x*x*x*x-3*x*x+1;
}
double df(double x){
    return 4*x*x*x-6*x;
}
double calc(double x){
    double derivative = df(x);
    if(fabs(derivative) < 1e-10){
        return x; // Return current value if derivative is zero
    }
    return x-f(x)/derivative;
}

int main(){
    freopen("input_newton-raphson.txt", "r", stdin);
    freopen("output_newton-raphson.txt", "w", stdout);
    
    double a, b, step, tolerance;
    int maxIterations;
    cin >> a >> b >> step >> tolerance >> maxIterations;
    
    double c;
vector<pair<double,double>>p;
for(double i=a;i<b;i+=step){
    if(f(i)*f(i+step)<0){
        p.push_back({i,i+step});
        i+=step*5;
    }
    //  if(f(a)*f(a-i)<0){
    //     p.push_back({a-i,a});
    //  }
}
int n=p.size(),i=0,j=0;
if(n<4){
for(double i=a;i>-500;i-=step){
    if(f(i)*f(i-step)<0){
        p.push_back({i-step,i});
        i-=step*5;
    }
    //  if(f(a)*f(a-i)<0){
    //     p.push_back({a-i,a});
    //  }
}
}
int m=p.size();
if(m == 0){
    cout << "No roots found in the given interval!" << endl;
    return 0;
}

cout << "\n========== NEWTON-RAPHSON METHOD RESULTS ==========" << endl;
cout << "Number of roots found: " << m << endl;
cout << "\nRoots:" << endl;

int rootNum = 1;
while(m--){
    c=(p[i].first+p[i].second)*0.5;
    int iterCount = 0;
    while(fabs(f(c))>tolerance && iterCount<maxIterations){
        double prev_c = c;
        c=calc(c);
        if(fabs(c - prev_c) < 1e-15) break; // Convergence stalled
        iterCount++;
        j++;
    }
    cout << "Root " << rootNum++ << ": " << fixed << setprecision(10) << c << " (iterations: " << iterCount << ")" << endl;
    i++;
}
cout << "\nTotal iterations across all roots: " << j << endl;

    return 0;
}