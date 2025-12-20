#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

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
    if(fabs(d)<EPS)return false;
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
    ifstream in("input/inverse_input.txt");
    ofstream out("output/inverse_output.txt");

    if (!in.is_open()) {
        cerr << "Error: Cannot open input file!\n";
        return 1;
    }

    int T;
    in >> T;

    out << "MATRIX INVERSE METHOD (ADJOINT METHOD)\n";
    out << "======================================\n\n";

    for(int tc=1; tc<=T; tc++){
        int n;
        in >> n;

        if (n <= 0 || n > 100) {
            cerr << "Error in test case " << tc << ": Invalid matrix size: " << n << "\n";
            out << "Test Case " << tc << ": ERROR - Invalid matrix size\n\n";
            continue;
        }

        vector<vector<double>> a(n,vector<double>(n));
        vector<vector<double>> A(n,vector<double>(n+1));
        vector<vector<double>> ad(n,vector<double>(n));
        vector<vector<double>> in_matrix(n,vector<double>(n));

        // Read augmented matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<=n;j++){
                in >> A[i][j];
            }
        }

        // Extract coefficient matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j]=A[i][j];
            }
        }

        out << "Test Case " << tc << ":\n";
        out << "Original Augmented Matrix [A|b]:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<=n;j++){
                out << setw(10) << fixed << setprecision(4) << A[i][j];
            }
            out << "\n";
        }

        // Calculate determinant
        double d = det(a,n);
        out << "\nDeterminant of A: " << fixed << setprecision(6) << d << "\n";

        if(fabs(d) < EPS){
            out << "\n→ Matrix is SINGULAR (det = 0)\n";
            out << "   Cannot find inverse. System may have:\n";
            out << "   - No solution (inconsistent)\n";
            out << "   - Infinite solutions (dependent)\n";
            out << "\n--------------------------------------\n\n";
            continue;
        }

        // Calculate adjoint
        adj(a,n,ad);
        out << "\nAdjoint Matrix (Adj(A)):\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                out << setw(12) << fixed << setprecision(6) << ad[i][j];
            }
            out << "\n";
        }

        // Calculate inverse
        inv(a,n,in_matrix);
        out << "\nInverse Matrix (A^-1 = Adj(A)/det(A)):\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                out << setw(12) << fixed << setprecision(6) << in_matrix[i][j];
            }
            out << "\n";
        }

        // Calculate solution: x = A^-1 * b
        out << "\nSolution (x = A^-1 * b):\n";
        for(int i=0;i<n;i++){
            double sum=0;
            for(int j=0;j<n;j++){
                sum += in_matrix[i][j] * A[j][n];
            }
            out << "x" << i+1 << " = " << setw(12) << fixed << setprecision(6) << sum << "\n";
        }

        // Verification
        out << "\nVerification (A * x):\n";
        for(int i=0;i<n;i++){
            double sum=0;
            for(int j=0;j<n;j++){
                sum += a[i][j] * (
                    [&](){
                        double val=0;
                        for(int k=0;k<n;k++)
                            val += in_matrix[j][k]*A[k][n];
                        return val;
                    }()
                );
            }
            out << "   " << setw(12) << fixed << setprecision(6) << sum 
                << " ≈ " << setw(12) << A[i][n] << "\n";
        }

        out << "\n--------------------------------------\n\n";
    }

    in.close();
    out.close();
    return 0;
}