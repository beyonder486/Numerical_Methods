#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x*x*x*x - 3*x*x + 1;
}

double df(double x) {
    return 4*x*x*x - 6*x;
}

int main() {
    ifstream input("input/input_newton-raphson.txt");
    ofstream output("output/output_newton-raphson.txt");

    int testCases;
    input >> testCases;

    for (int tc = 1; tc <= testCases; tc++) {
        double x, tolerance;
        int maxIterations;
        input >> x >> tolerance >> maxIterations;

        output << "========== TEST CASE " << tc << " ==========\n\n";
        output << "Initial guess: " << fixed << setprecision(10) << x << "\n";
        output << "Tolerance: " << tolerance << "\n\n";

        output << left << setw(5) << "Iter"
               << setw(20) << "x_n"
               << setw(20) << "f(x_n)" << "\n";

        bool converged = false;

        for (int iter = 1; iter <= maxIterations; iter++) {
            double fx = f(x);
            double dfx = df(x);

            output << left << setw(5) << iter
                   << setw(20) << x
                   << setw(20) << scientific << fx << fixed << "\n";

            if (fabs(dfx) < 1e-12) {
                output << "\nWARNING: Derivative near zero. Method fails.\n";
                break;
            }

            double x_new = x - fx / dfx;

            if (fabs(x_new - x) < tolerance || fabs(f(x_new)) < tolerance) {
                converged = true;
                x = x_new;
                output << "\n========== RESULT ==========\n";
                output << "Root: " << fixed << setprecision(10) << x << "\n";
                output << "Iterations: " << iter << "\n";
                output << "f(root): " << scientific << f(x) << "\n\n";
                break;
            }

            x = x_new;
        }

        if (!converged) {
            output << "\n========== WARNING ==========\n";
            output << "Maximum iterations reached without convergence.\n";
            output << "Last approximation: " << fixed << setprecision(10) << x << "\n";
            output << "f(x): " << scientific << f(x) << "\n\n";
        }
    }

    input.close();
    output.close();

    cout << "All test cases processed successfully!" << endl;
    return 0;
}
