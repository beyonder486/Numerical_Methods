#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return 2*x*x - 7*x + 2;
}

int main() {
    ifstream input("input/input_regularfalsi.txt");
    ofstream output("output/output_regularfalsi.txt");

    if (!input.is_open()) {
        cerr << "Error: Cannot open input file\n";
        return 1;
    }

    int testCases;
    input >> testCases;

    for (int tc = 1; tc <= testCases; tc++) {
        double a, b, tolerance;
        int maxIterations;
        input >> a >> b >> tolerance >> maxIterations;

        output << "========== TEST CASE " << tc << " ==========\n\n";

        if (a > b) swap(a, b);

        if (f(a) * f(b) >= 0) {
            output << "ERROR: No sign change in interval ["
                   << a << ", " << b << "]\n\n";
            continue;
        }

        output << "Initial interval: [" << a << ", " << b << "]\n";
        output << "Tolerance: " << tolerance << "\n\n";

        output << left << setw(5) << "Iter"
               << setw(15) << "a"
               << setw(15) << "b"
               << setw(15) << "c"
               << setw(15) << "f(c)" << "\n";

        bool converged = false;
        double c = a;

        for (int iter = 1; iter <= maxIterations; iter++) {
            double fa = f(a);
            double fb = f(b);

            double denom = fb - fa;
            if (fabs(denom) < 1e-12) {
                output << "\nWARNING: Denominator near zero. Method fails.\n";
                break;
            }

            c = a - fa * (b - a) / denom;
            double fc = f(c);

            output << left << setw(5) << iter
                   << setw(15) << a
                   << setw(15) << b
                   << setw(15) << c
                   << setw(15) << scientific << fc << fixed << "\n";

            if (fabs(fc) < tolerance || fabs(b - a) < tolerance) {
                converged = true;
                output << "\n========== RESULT ==========\n";
                output << "Root: " << fixed << setprecision(10) << c << "\n";
                output << "Iterations: " << iter << "\n";
                output << "f(root): " << scientific << fc << "\n\n";
                break;
            }

            if (fa * fc < 0)
                b = c;
            else
                a = c;
        }

        if (!converged) {
            output << "\n========== WARNING ==========\n";
            output << "Maximum iterations reached without convergence.\n";
            output << "Last approximation: " << fixed << setprecision(10) << c << "\n";
            output << "f(x): " << scientific << f(c) << "\n\n";
        }
    }

    input.close();
    output.close();

    cout << "All test cases processed successfully!\n";
    return 0;
}
