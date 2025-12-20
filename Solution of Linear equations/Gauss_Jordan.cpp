#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

int main() {
    ifstream in("input/gauss_jordan_input.txt");
    ofstream out("output/gauss_jordan_output.txt");

    // Check if file opened successfully
    if (!in.is_open()) {
        cerr << "Error: Cannot open input file!\n";
        return 1;
    }

    int T;
    in >> T;

    // Validate number of test cases
    if (T <= 0 || T > 100) {
        cerr << "Error: Invalid number of test cases: " << T << "\n";
        return 1;
    }

    out << "GAUSS JORDAN METHOD WITH SOLUTION ANALYSIS\n";
    out << "=========================================\n\n";

    for (int tc = 1; tc <= T; tc++) {
        int n;
        in >> n;

        // Validate matrix size
        if (n <= 0 || n > 1000) {
            cerr << "Error in test case " << tc << ": Invalid matrix size: " << n << "\n";
            out << "Test Case " << tc << ": ERROR - Invalid matrix size\n\n";
            continue;
        }

        vector<vector<double>> a(n, vector<double>(n + 1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= n; j++)
                in >> a[i][j];

        out << "Test Case " << tc << ":\n";
        out << "Original Augmented Matrix:\n";
        for (auto &r : a) {
            for (double v : r)
                out << setw(10) << v;
            out << "\n";
        }

        // Gauss-Jordan with partial pivoting
        int rank = 0;
        for (int col = 0; col < n; col++) {
            // Find pivot (largest element in current column)
            int pivotRow = rank;
            for (int i = rank + 1; i < n; i++) {
                if (fabs(a[i][col]) > fabs(a[pivotRow][col])) {
                    pivotRow = i;
                }
            }

            // Skip if column is all zeros
            if (fabs(a[pivotRow][col]) < EPS) continue;

            // Swap rows
            if (pivotRow != rank) {
                swap(a[rank], a[pivotRow]);
            }

            // Normalize pivot row
            double pivot = a[rank][col];
            for (int j = 0; j <= n; j++)
                a[rank][j] /= pivot;

            // Eliminate column in all other rows
            for (int i = 0; i < n; i++) {
                if (i == rank) continue;
                double factor = a[i][col];
                for (int j = 0; j <= n; j++)
                    a[i][j] -= factor * a[rank][j];
            }

            rank++;
        }

        out << "\nReduced Row Echelon Form (RREF):\n";
        for (auto &r : a) {
            for (double v : r)
                out << setw(10) << v;
            out << "\n";
        }

        // Check for inconsistency
        bool noSolution = false;
        for (int i = rank; i < n; i++) {
            if (fabs(a[i][n]) > EPS) {
                noSolution = true;
                break;
            }
        }

        out << "\nSystem Analysis:\n";
        out << "Rank of coefficient matrix: " << rank << "\n";
        
        if (noSolution) {
            out << "→ No Solution (Inconsistent system)\n";
            out << "   (0 = non-zero constant in reduced form)\n";
        }
        else if (rank < n) {
            out << "→ Infinite Solutions (Dependent system)\n";
            out << "   (" << (n - rank) << " free variable(s))\n";
        }
        else {
            out << "→ Unique Solution Exists\n\nSolution:\n";
            for (int i = 0; i < n; i++)
                out << "x" << i + 1 << " = " << fixed << setprecision(6) << a[i][n] << "\n";
        }

        out << "\n--------------------------------------\n\n";
    }

    in.close();
    out.close();
    return 0;
}

