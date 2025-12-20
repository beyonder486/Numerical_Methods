#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

int main() {
    ifstream in("gj_input.txt");
    ofstream out("gj_output.txt");

    int T;
    in >> T;

    out << "GAUSS JORDAN METHOD WITH SOLUTION ANALYSIS\n";
    out << "=========================================\n\n";

    for (int tc = 1; tc <= T; tc++) {
        int n;
        in >> n;

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

        for (int i = 0; i < n; i++) {
            if (fabs(a[i][i]) < EPS) continue;

            double pivot = a[i][i];
            for (int j = 0; j <= n; j++)
                a[i][j] /= pivot;

            for (int k = 0; k < n; k++) {
                if (k == i) continue;
                double factor = a[k][i];
                for (int j = 0; j <= n; j++)
                    a[k][j] -= factor * a[i][j];
            }
        }

        out << "\nReduced Row Echelon Form (RREF):\n";
        for (auto &r : a) {
            for (double v : r)
                out << setw(10) << v;
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
            for (int i = 0; i < n; i++)
                out << "x" << i + 1 << " = " << a[i][n] << "\n";
        }

        out << "\n--------------------------------------\n\n";
    }
}

