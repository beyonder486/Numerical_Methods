#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return 2*x*x-9*x+2;
}

int main(){
    double a=0,b=1,lim=0;
    while(f(a)*f(b)>0 && lim<100){
        b++;
        lim++;
    }
    double c=a-f(a)*(b-a)/(f(b)-f(a));
    int it=0;
    while(fabs(f(c))>0.0000001){
        if(f(a)*f(c)<0)b=c;
        else a=c;
        c=a-f(a)*(b-a)/(f(b)-f(a));
        it++;
    }
    cout<<c<<" "<<it<<endl;

    return 0;
}