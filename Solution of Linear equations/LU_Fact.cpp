#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("lu_input.txt");
    ofstream out("lu_output.txt");

    int n;
    in >> n;

    vector<vector<double>> A(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            in >> A[i][j];

    vector<vector<double>> L(n, vector<double>(n, 0)),
                           U(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += L[i][j] * U[j][k];
            U[i][k] = A[i][k] - sum;
        }

        for (int k = i; k < n; k++) {
            if (i == k)
                L[i][i] = 1;
            else {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += L[k][j] * U[j][i];
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }

    out << "LU FACTORIZATION METHOD\n";
    out << "======================\n\n";

    out << "Input Coefficient Matrix:\n";
    for (auto &r : A) {
        for (double v : r)
            out << setw(8) << v;
        out << "\n";
    }

    out << "\nLower Triangular Matrix (L):\n";
    for (auto &r : L) {
        for (double v : r)
            out << setw(8) << v;
        out << "\n";
    }

    out << "\nUpper Triangular Matrix (U):\n";
    for (auto &r : U) {
        for (double v : r)
            out << setw(8) << v;
        out << "\n";
    }

    out << "\nSystem Analysis:\n";
    out << "→ Unique Solution Required\n";
    out << "→ LU factorization not applicable for infinite or inconsistent systems\n";
}

