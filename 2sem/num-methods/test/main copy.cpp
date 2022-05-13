#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<double>> ober_matr(vector<vector<double>> a)
{
    double det;
    vector<vector<double>> b(2, vector<double>(2));
    det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    b[0][0] = (1 / det) * a[1][1];
    b[0][1] = -(1 / det) * a[1][0];
    b[1][0] = -(1 / det) * a[0][1];
    b[1][1] = (1 / det) * a[0][0];
    // cout << a[0][0] << " " << a[0][1] << "\n";
    // cout << a[1][0] << " " << a[1][1] << "\n";
    a = b;
    double t = a[1][0];
    a[1][0] = a[0][1];
    a[0][1] = t;
    return a;
}

vector<vector<double>> df(vector<double> X)
{
    vector<vector<double>> df(2, vector<double>(2));
    df[0][0] = 2;
    df[0][1] = sin(X[1] + 1);
    df[1][0] = cos(X[0]);
    df[1][1] = 1;
    return ober_matr(df);
}

vector<double> F(vector<double> X)
{
    vector<double> f(2);
    f[0] = 2 * X[0] - cos(X[1] + 1);
    f[1] = X[1] + sin(X[0]) + 0.4;
    return (f);
}

int main()
{

    vector<double> X(2);
    X = {1, 1};
    vector<double> Xlast(2);
    vector<vector<double>> W(2, vector<double>(2));
    vector<double> dX(2);
    dX = {2, 2};
    double e = 0.00001; // точность

    while ((abs(dX[0]) + abs(dX[1])) > e)
    {
        Xlast = X;
        cout << X[0] << ' ' << X[1] << endl;

        W = df(X); // матрица Якоби ^-1
        vector<double> f = F(X);

        /*Умножение W на F(X)*/
        f[0] = W[0][0] * f[0] + W[0][1] * f[0];
        f[1] = W[1][0] * f[1] + W[1][1] * f[1];
        /*X = X - W*F(X)*/
        X[0] = X[0] - f[0];
        X[1] = X[1] - f[1];

        dX[0] = X[0] - Xlast[0];
        dX[1] = X[1] - Xlast[1];
    }

    cout << X[0] << ' ' << X[1];

    return 0;
}