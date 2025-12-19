#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, degree;
    cin >> n >> degree;
    
    vector<double> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    
    int m = degree + 1;
    vector<vector<double>> A(m, vector<double>(m + 1, 0));
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                A[i][j] += pow(x[k], i + j);
            }
        }
        for(int k = 0; k < n; k++){
            A[i][m] += y[k] * pow(x[k], i);
        }
    }
    
    // Gauss-Jordan Elimination
    for(int i = 0; i < m; i++){
        // Make diagonal element 1
        double pivot = A[i][i];
        for(int j = 0; j <= m; j++){
            A[i][j] /= pivot;
        }
        
        // Make all other elements in column 0
        for(int k = 0; k < m; k++){
            if(k != i){
                double factor = A[k][i];
                for(int j = 0; j <= m; j++){
                    A[k][j] -= factor * A[i][j];
                }
            }
        }
    }
    
    cout << "y = ";
    for(int i = 0; i <= degree; i++){
        if(i > 0 && A[i][m] >= 0) cout << " + ";
        else if(i > 0) cout << " - ";
        
        if(i == 0) cout << A[i][m];
        else if(i == 1) cout << fabs(A[i][m]) << "x";
        else cout << fabs(A[i][m]) << "x^" << i;
    }
    cout << endl;
    
    return 0;
}