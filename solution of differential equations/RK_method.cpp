#include <bits/stdc++.h>
using namespace std;

// Function 1: dy/dx = x + y (Simple, always works)
double f1(double x, double y) {
    return x + y;
}

// Function 2: dy/dx = -50(y - cos(x)) (Stiff equation - RK struggles with large step sizes)
double f2(double x, double y) {
    return -50 * (y - cos(x));
}

// Function 3: dy/dx = y^2 (Can blow up - solution may not exist for all x)
double f3(double x, double y) {
    return y * y;
}

// Function 4: dy/dx = -y/x (Has singularity at x=0)
double f4(double x, double y) {
    if (abs(x) < 1e-10) return 1e10; // Singularity indicator
    return -y / x;
}

void solveRK(int testCase, string equation, double (*func)(double, double), 
             double x0, double y0, double xn, double h, ofstream& out) {
    
    out << "Test Case " << testCase << ":\n";
    out << "Differential Equation: " << equation << "\n";
    out << "Initial Condition: y(" << x0 << ") = " << y0 << "\n";
    out << "Step size (h) = " << h << "\n";
    out << "Target x = " << xn << "\n\n";

    out << "Step-by-step Computation:\n";
    out << setw(8) << "x"
        << setw(12) << "y"
        << setw(12) << "k1"
        << setw(12) << "k2"
        << setw(12) << "k3"
        << setw(12) << "k4"
        << "\n";

    bool failed = false;
    int steps = 0;
    int maxSteps = 1000;

    while (x0 < xn - 1e-9 && steps < maxSteps && !failed) {
        double k1 = h * func(x0, y0);
        double k2 = h * func(x0 + h / 2, y0 + k1 / 2);
        double k3 = h * func(x0 + h / 2, y0 + k2 / 2);
        double k4 = h * func(x0 + h, y0 + k3);

        out << fixed << setprecision(4);
        out << setw(8) << x0
            << setw(12) << y0
            << setw(12) << k1
            << setw(12) << k2
            << setw(12) << k3
            << setw(12) << k4
            << "\n";

        double y_new = y0 + (k1 + 2*k2 + 2*k3 + k4) / 6;
        
        // Check for overflow/instability
        if (isnan(y_new) || isinf(y_new) || abs(y_new) > 1e10) {
            out << "\n*** NUMERICAL INSTABILITY DETECTED ***\n";
            out << "Solution diverged at x = " << x0 + h << "\n";
            failed = true;
            break;
        }

        y0 = y_new;
        x0 = x0 + h;
        steps++;
    }

    if (!failed && steps < maxSteps) {
        out << "\nFinal Result:\n";
        out << "y(" << xn << ") = " << y0 << "\n";
        out << "\nStatus: ✓ Solution computed successfully\n";
    } else if (steps >= maxSteps) {
        out << "\n*** WARNING: Maximum iterations reached ***\n";
        out << "Status: ✗ Solution may be unreliable\n";
    } else {
        out << "Status: ✗ RK method failed for this problem/step size\n";
    }

    out << "\n--------------------------------------\n\n";
}

int main() {
    ifstream in("input/rk_input.txt");
    ofstream out("output/rk_output.txt");

    int T;
    in >> T;

    out << "RUNGE-KUTTA METHOD (4th ORDER)\n";
    out << "=============================\n\n";

    for (int tc = 1; tc <= T; tc++) {
        int funcType;
        double x0, y0, xn, h;
        in >> funcType >> x0 >> y0 >> xn >> h;

        switch(funcType) {
            case 1:
                solveRK(tc, "dy/dx = x + y", f1, x0, y0, xn, h, out);
                break;
            case 2:
                solveRK(tc, "dy/dx = -50(y - cos(x)) [STIFF]", f2, x0, y0, xn, h, out);
                break;
            case 3:
                solveRK(tc, "dy/dx = y² [CAN BLOW UP]", f3, x0, y0, xn, h, out);
                break;
            case 4:
                solveRK(tc, "dy/dx = -y/x [SINGULARITY AT x=0]", f4, x0, y0, xn, h, out);
                break;
        }
    }

    out << "Method Analysis:\n";
    out << "→ RK4 works well for non-stiff ODEs with reasonable step sizes\n";
    out << "→ Stiff equations require very small h or implicit methods\n";
    out << "→ Solutions can blow up or become undefined\n";
    out << "→ Singularities cause numerical instability\n";

    return 0;
}
