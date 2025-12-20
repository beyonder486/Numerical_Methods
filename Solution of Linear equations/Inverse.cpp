 #include<bits/stdc++.h>
using namespace std;

double det(vector<vector<double>>&a,int n){
    if(n==1)return a[0][0];
    if(n==2)return a[0][0]*a[1][1]-a[0][1]*a[1][0];
    vector<vector<double>>sub(n-1,vector<double>(n-1));
    double d=0;
    for(int x=0;x<n;x++){
        int subi=0;
        for(int i=1;i<n;i++){
            int subj=0;
            for(int j=0;j<n;j++){
                if(j==x)continue;
                sub[subi][subj]=a[i][j];
                subj++;
            }
            subi++;
        }
        d+=pow(-1,x)*a[0][x]*det(sub,n-1);
    }
    return d;
}
void cof(vector<vector<double>>&a,int n,int p,int q,vector<vector<double>>&temp){
    int i=0,j=0;
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            if(r!=p && c!=q){
                temp[i][j++]=a[r][c];
                if(j==n-1){
                    j=0;
                    i++;
                }
            }
        }
    }
}
void adj(vector<vector<double>>&a,int n,vector<vector<double>>&ad){
    if(n==1){
        ad[0][0]=1;
        return;
    }
    vector<vector<double>>temp(n-1,vector<double>(n-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cof(a,n,i,j,temp);
            int sign=((i+j)%2==0)?1:-1;
            ad[j][i]=sign*det(temp,n-1);
        }
    }
}
bool inv(vector<vector<double>>&a,int n,vector<vector<double>>&in){
    double d=det(a,n);
    if(d==0)return false;
    vector<vector<double>>ad(n,vector<double>(n));
    adj(a,n,ad);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            in[i][j]=ad[i][j]/d;
        }
    }
    return true;
}
void displayCofactorMatrix(vector<vector<double>>&a, int n){
    cout << "\nCofactor Matrices:" << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << "\nCofactor for element (" << i << "," << j << "):" << endl;
            vector<vector<double>>temp(n-1,vector<double>(n-1));
            cof(a,n,i,j,temp);
            for(int r=0;r<n-1;r++){
                for(int c=0;c<n-1;c++){
                    cout << fixed << setprecision(4) << setw(10) << temp[r][c] << " ";
                }
                cout << endl;
            }
        }
    }
}

int main(){
    int n;cin>>n;
    vector<vector<double>>a(n,vector<double>(n)),ad(n,vector<double>(n)),in(n,vector<double>(n)),A(n,vector<double>(n+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++)cin>>A[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)a[i][j]=A[i][j];
    }
    
    displayCofactorMatrix(a, n);
    
    adj(a,n,ad);
    inv(a,n,in);
    for(int i=0;i<n;i++){
        double sum=0;
        for(int j=0;j<n;j++){
            sum+=in[i][j]*A[j][n];
        }
        cout<<sum<<endl;
    }
    cout<<det(a,n)<<endl;

    return 0;
}