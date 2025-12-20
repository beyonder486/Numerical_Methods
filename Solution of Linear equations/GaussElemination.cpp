#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

int main() {
    ifstream in("input/gauss_input.txt");
    ofstream out("output/gauss_output.txt");

    int T;
    in >> T;

    out << "GAUSS ELIMINATION WITH SOLUTION ANALYSIS\n";
    out << "======================================\n\n";

    for (int tc = 1; tc <= T; tc++) {
        int n;
        in >> n;

        vector<vector<double>> a(n, vector<double>(n + 1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= n; j++)
                in >> a[i][j];

        out << "Test Case " << tc << ":\n";
        out << "Original Augmented Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++)
                out << setw(10) << a[i][j];
            out << "\n";
        }

        // Forward Elimination
        for (int i = 0; i < n; i++) {
            if (fabs(a[i][i]) < EPS) continue;
            for (int k = i + 1; k < n; k++) {
                double factor = a[k][i] / a[i][i];
                for (int j = i; j <= n; j++)
                    a[k][j] -= factor * a[i][j];
            }
        }

        out << "\nUpper Triangular Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++)
                out << setw(10) << a[i][j];
            out << "\n";
        }

        bool noSolution = false;
        int pivotCount = 0;

        for (int i = 0; i < n; i++) {
            bool allZero = true;
            for (int j = 0; j < n; j++)
                if (fabs(a[i][j]) > EPS)
                    allZero = false;

            if (allZero && fabs(a[i][n]) > EPS)
                noSolution = true;

            if (!allZero) pivotCount++;
        }

        out << "\nSystem Analysis:\n";
        if (noSolution) {
            out << "→ No Solution (Inconsistent system)\n";
        }
        else if (pivotCount < n) {
            out << "→ Infinite Solutions (Dependent system)\n";
        }
        else {
            out << "→ Unique Solution Exists\n\nSolution:\n";
            vector<double> x(n);
            for (int i = n - 1; i >= 0; i--) {
                double sum = a[i][n];
                for (int j = i + 1; j < n; j++)
                    sum -= a[i][j] * x[j];
                x[i] = sum / a[i][i];
            }
            for (int i = 0; i < n; i++)
                out << "x" << i + 1 << " = " << x[i] << "\n";
        }

        out << "\n--------------------------------------\n\n";
    }
}
