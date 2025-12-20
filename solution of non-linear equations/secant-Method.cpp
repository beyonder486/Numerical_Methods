#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x*x*x*x - 3*x*x + 1;
}

int main() {
    ifstream input("input/input_secant.txt");
    ofstream output("output/output_secant.txt");

    if (!input.is_open()) {
        cerr << "Error: Cannot open input file" << endl;
        return 1;
    }

    int testCases;
    input >> testCases;

    for (int tc = 1; tc <= testCases; tc++) {
        double x0, x1, tolerance;
        int maxIterations;

        input >> x0 >> x1 >> tolerance >> maxIterations;

        output << "========== TEST CASE " << tc << " ==========\n\n";
        output << "Initial guesses: x0 = " << fixed << setprecision(10) << x0
               << ", x1 = " << x1 << "\n";
        output << "Tolerance: " << tolerance << "\n";
        output << "Max iterations: " << maxIterations << "\n\n";

        output << left << setw(5) << "Iter"
               << setw(15) << "x0"
               << setw(15) << "x1"
               << setw(15) << "x2"
               << setw(15) << "f(x2)" << "\n";

        bool converged = false;
        double x2 = x1;

        for (int iter = 1; iter <= maxIterations; iter++) {
            double fx0 = f(x0);
            double fx1 = f(x1);

            double denom = fx1 - fx0;
            if (fabs(denom) < 1e-12) {
                output << "\nWARNING: Denominator near zero. Secant method fails.\n";
                break;
            }

            x2 = x1 - fx1 * (x1 - x0) / denom;
            double fx2 = f(x2);

            output << left << setw(5) << iter
                   << setw(15) << x0
                   << setw(15) << x1
                   << setw(15) << x2
                   << setw(15) << scientific << fx2 << fixed << "\n";

            if (fabs(x2 - x1) < tolerance || fabs(fx2) < tolerance) {
                converged = true;
                output << "\n========== RESULT ==========\n";
                output << "Root: " << fixed << setprecision(10) << x2 << "\n";
                output << "Iterations: " << iter << "\n";
                output << "f(root): " << scientific << fx2 << "\n\n";
                break;
            }

            x0 = x1;
            x1 = x2;
        }

        if (!converged) {
            output << "\n========== WARNING ==========\n";
            output << "Method did not converge within the maximum iterations.\n";
            output << "Last approximation: " << fixed << setprecision(10) << x2 << "\n";
            output << "f(x): " << scientific << f(x2) << "\n\n";
        }
    }

    input.close();
    output.close();

    cout << "All test cases processed successfully!" << endl;
    return 0;
}
