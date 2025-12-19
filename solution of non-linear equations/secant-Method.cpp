#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return x*x*x*x-3*x*x+1;
}
// double df(double x){
//     return 4*x*x*x-6*x;
// }
double calc(double x,double y){
    return x-f(x)*(x-y)/(f(x)-f(y));
}
int main(){
    double a=-3,b=3,c=0,step=0.1;
    vector<pair<double,double>>p;
    for(double i=a;i<b;i+=step){
        if(f(i)*f(i+step)<0){
            p.push_back({i,i+step});
            i+=0.5;
        }
    }
    int n=p.size(),i=0,j=0;
    while(n--){
        double x1=p[i].second;
        double x0=p[i].first;
        c=(x0+x1)/2;
        while(fabs(f(c))>1e-6){
            c=calc(x1,x0);
            x0=x1;
            x1=c;
            j++;
        }
        i++;
        cout<<c<<" ";
    }
    cout<<endl;
    for(auto& i:p)cout<<i.first<<" "<<i.second<<",";
    cout<<endl;
    cout<<j<<endl;
    return 0;
}