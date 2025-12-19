#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return 2*x*x-9*x+2;
}

int main(){
    double a=0,b=-2,limit=0;
    double res=0,r=0;
    bool tf1=false,tf2=false;
    if(fabs(f(a))<0.0001){
        tf1=true;
        res=a;
    }
    while(f(a)*f(b)>0 && limit<100){
        if(fabs(f(b))<0.0001){
            tf2=true;
            r=b;
        }
        b++;
        limit++;
    }
    double c=(a+b)/2;
    int i=0;
    while(fabs(f(c))>0.0001){
        if(f(a)*f(c)<0)b=c;
        else a=c;
        c=(a+b)/2;
        i++;
    }
    if(tf1)cout<<res<<endl;
    if(tf2)cout<<r<<endl;
    cout<<c<<" "<<i<<endl;

    return 0;
}