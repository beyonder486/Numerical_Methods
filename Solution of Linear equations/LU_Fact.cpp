#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

int main() {
    ifstream in("input/lu_input.txt");
    ofstream out("output/lu_output.txt");

    if (!in.is_open()) {
        cerr << "Error: Cannot open input file!\n";
        return 1;
    }

    int T;
    in >> T;

    if (T <= 0 || T > 100) {
        cerr << "Error: Invalid number of test cases: " << T << "\n";
        return 1;
    }

    out << "LU FACTORIZATION METHOD\n";
    out << "=======================\n\n";

    for (int tc = 1; tc <= T; tc++) {
        int n;
        in >> n;

        if (n <= 0 || n > 1000) {
            cerr << "Error in test case " << tc << ": Invalid matrix size: " << n << "\n";
            out << "Test Case " << tc << ": ERROR - Invalid matrix size\n\n";
            continue;
        }

        vector<vector<double>> A(n, vector<double>(n + 1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= n; j++)
                in >> A[i][j];

        out << "Test Case " << tc << ":\n";
        out << "Original Augmented Matrix [A|b]:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++)
                out << setw(10) << fixed << setprecision(4) << A[i][j];
            out << "\n";
        }

        // Extract coefficient matrix
        vector<vector<double>> coeff(n, vector<double>(n));
        vector<double> b(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                coeff[i][j] = A[i][j];
            b[i] = A[i][n];
        }

        vector<vector<double>> L(n, vector<double>(n, 0)),
                               U(n, vector<double>(n, 0));

        bool singular = false;
        int rank = 0;

        // LU Decomposition with rank tracking
        for (int i = 0; i < n; i++) {
            // Compute U matrix (upper triangular)
            for (int k = i; k < n; k++) {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += L[i][j] * U[j][k];
                U[i][k] = coeff[i][k] - sum;
            }

            // Check for zero pivot
            if (fabs(U[i][i]) < EPS) {
                singular = true;
                break;
            }

            rank++;

            // Compute L matrix (lower triangular)
            for (int k = i; k < n; k++) {
                if (i == k)
                    L[i][i] = 1;
                else {
                    double sum = 0;
                    for (int j = 0; j < i; j++)
                        sum += L[k][j] * U[j][i];
                    L[k][i] = (coeff[k][i] - sum) / U[i][i];
                }
            }
        }

        out << "\nLower Triangular Matrix (L):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                out << setw(10) << fixed << setprecision(6) << L[i][j];
            out << "\n";
        }

        out << "\nUpper Triangular Matrix (U):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                out << setw(10) << fixed << setprecision(6) << U[i][j];
            out << "\n";
        }

        out << "\nSystem Analysis:\n";
        out << "Rank of coefficient matrix: " << rank << "\n";

        if (singular || rank < n) {
            out << "→ Matrix is SINGULAR (det = 0)\n";
            out << "   System has either:\n";
            out << "   - No solution (inconsistent)\n";
            out << "   - Infinite solutions (dependent)\n";
            out << "   LU factorization cannot proceed.\n";
        }
        else {
            out << "→ Unique Solution Exists\n";

            // Forward substitution: Ly = b
            vector<double> y(n);
            for (int i = 0; i < n; i++) {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += L[i][j] * y[j];
                y[i] = b[i] - sum;
            }

            out << "\nForward Substitution (Ly = b):\n";
            for (int i = 0; i < n; i++)
                out << "y" << i + 1 << " = " << setw(12) << fixed << setprecision(6) << y[i] << "\n";

            // Backward substitution: Ux = y
            vector<double> x(n);
            for (int i = n - 1; i >= 0; i--) {
                double sum = 0;
                for (int j = i + 1; j < n; j++)
                    sum += U[i][j] * x[j];
                x[i] = (y[i] - sum) / U[i][i];
            }

            out << "\nBackward Substitution (Ux = y):\n";
            out << "Solution:\n";
            for (int i = 0; i < n; i++)
                out << "x" << i + 1 << " = " << setw(12) << fixed << setprecision(6) << x[i] << "\n";

            // Verification: Ax = b
            out << "\nVerification (Ax = b):\n";
            for (int i = 0; i < n; i++) {
                double sum = 0;
                for (int j = 0; j < n; j++)
                    sum += coeff[i][j] * x[j];
                out << "   " << setw(12) << fixed << setprecision(6) << sum
                    << " ≈ " << setw(12) << b[i] << "\n";
            }
        }

        out << "\n--------------------------------------\n\n";
    }

    in.close();
    out.close();
    return 0;
}

