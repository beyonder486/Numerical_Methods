 #include <bits/stdc++.h>
using namespace std;

double func(double x) {
    return x*x + sin(x);  // function definition
}

void print_table(vector<double>& x, vector<vector<double>>& diff, int n, ofstream& out) {
    out << "Backward Difference Table:\n";
    out << setw(10) << "x";
    out << setw(10) << "f(x)";
    for(int i=1;i<n;i++)
        out << setw(10) << "∇^" << i;
    out << "\n";

    for(int i=0;i<n;i++){
        out << setw(10) << x[i];
        for(int j=0;j<=i;j++)
            out << setw(10) << diff[i][j];
        out << "\n";
    }
}

int main() {
    ifstream in("input/backward_input.txt");
    ofstream out("output/backward_output.txt");

    int T;
    in >> T;

    for(int t=1;t<=T;t++){
        int n;
        in >> n;
        vector<double> x(n), fx(n);
        for(int i=0;i<n;i++) in >> x[i];
        for(int i=0;i<n;i++) fx[i]=func(x[i]);

        // backward difference table
        vector<vector<double>> diff(n, vector<double>(n,0));
        for(int i=0;i<n;i++) diff[i][0]=fx[i];

        for(int j=1;j<n;j++)
            for(int i=j;i<n;i++)
                diff[i][j]=diff[i][j-1]-diff[i-1][j-1];

        out << "Test Case " << t << ":\n";
        out << "Given Data Table:\n";
        out << setw(10) << "x" << setw(10) << "f(x)\n";
        for(int i=0;i<n;i++)
            out << setw(10) << x[i] << setw(10) << fx[i] << "\n";

        print_table(x,diff,n,out);

        double h=x[1]-x[0];

        // First derivative
        vector<double> first_derivative(n-1);
        for(int i=1;i<n;i++)
            first_derivative[i-1]=(diff[i][1])/h;

        // Second derivative
        vector<double> second_derivative(n-2);
        for(int i=2;i<n;i++)
            second_derivative[i-2]=(diff[i][0]-2*diff[i-1][0]+diff[i-2][0])/(h*h);

        out << "\nFirst Derivative:\n";
        for(int i=1;i<n;i++)
            out << "f'(" << x[i] << ") = " << first_derivative[i-1] << "\n";

        out << "\nSecond Derivative:\n";
        for(int i=2;i<n;i++)
            out << "f''(" << x[i] << ") = " << second_derivative[i-2] << "\n";

        out << "\n--------------------------------------\n\n";
    }
}
