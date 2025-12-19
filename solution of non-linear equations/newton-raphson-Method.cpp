#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return x*x*x*x-3*x*x+1;
}
double df(double x){
    return 4*x*x*x-6*x;
}
double calc(double x){
    return x-f(x)/df(x);
}

int main(){
double a=-1,b=2,c,d=0.1;
vector<pair<double,double>>p;
for(double i=a;i<b;i+=d){
    if(f(i)*f(i+d)<0){
        p.push_back({i,i+d});
        i+=d*5;
    }
    //  if(f(a)*f(a-i)<0){
    //     p.push_back({a-i,a});
    //  }
}
int n=p.size(),i=0,j=0;
if(n<4){
for(double i=a;i>-500;i-=d){
    if(f(i)*f(i-d)<0){
        p.push_back({i-d,i});
        i-=d*5;
    }
    //  if(f(a)*f(a-i)<0){
    //     p.push_back({a-i,a});
    //  }
}
}
int m=p.size();
while(m--){
    c=(p[i].first+p[i].second)*0.5;
    while(fabs(f(c))>1e-6){
        c=calc(c);
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