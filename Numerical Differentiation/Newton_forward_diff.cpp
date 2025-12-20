#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9

double func(double x) {
    return x*x + sin(x);  // function definition
}

// Print difference table
void print_table(vector<double>& x, vector<vector<double>>& diff, int n, ofstream& out) {
    out << "Forward Difference Table:\n";
    out << setw(10) << "x";
    out << setw(10) << "f(x)";
    for(int i=1;i<n;i++)
        out << setw(10) << "Δ^" << i;
    out << "\n";

    for(int i=0;i<n;i++){
        out << setw(10) << x[i];
        for(int j=0;j<n-i;j++)
            out << setw(10) << diff[i][j];
        out << "\n";
    }
}

int main() {
    ifstream in("input/forward_input.txt");
    ofstream out("output/forward_output.txt");

    int T;
    in >> T;

    for(int t=1; t<=T; t++){
        int n;
        in >> n;
        vector<double> x(n), fx(n);
        for(int i=0;i<n;i++) in >> x[i];

        for(int i=0;i<n;i++) fx[i]=func(x[i]);

        // Create forward difference table
        vector<vector<double>> diff(n, vector<double>(n,0));
        for(int i=0;i<n;i++) diff[i][0]=fx[i];

        for(int j=1;j<n;j++)
            for(int i=0;i<n-j;i++)
                diff[i][j]=diff[i+1][j-1]-diff[i][j-1];

        out << "Test Case " << t << ":\n";
        out << "Given Data Table:\n";
        out << setw(10) << "x" << setw(10) << "f(x)\n";
        for(int i=0;i<n;i++)
            out << setw(10) << x[i] << setw(10) << fx[i] << "\n";

        print_table(x,diff,n,out);

        // Step size assuming uniform
        double h = x[1]-x[0];

        // First derivative using forward difference formula
        vector<double> first_derivative(n-1);
        for(int i=0;i<n-1;i++)
            first_derivative[i]=(diff[i][1])/h;

        // Second derivative using forward difference formula
        vector<double> second_derivative(n-2);
        for(int i=0;i<n-2;i++)
            second_derivative[i]=(diff[i+2][0]-2*diff[i+1][0]+diff[i][0])/(h*h);

        out << "\nFirst Derivative:\n";
        for(int i=0;i<n-1;i++)
            out << "f'(" << x[i] << ") = " << first_derivative[i] << "\n";

        out << "\nSecond Derivative:\n";
        for(int i=0;i<n-2;i++)
            out << "f''(" << x[i] << ") = " << second_derivative[i] << "\n";

        out << "\n--------------------------------------\n\n";
    }
}
