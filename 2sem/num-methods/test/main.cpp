#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


vector < vector <double> > ober_matr(vector < vector <double> > a)
{
    double det;
    vector < vector <double> > b(2, vector<double>(2));
    det = a[0][0]*a[1][1] - a[0][1]*a[1][0];
    b[0][0] = (1/det)*a[1][1];
    b[0][1] = - (1/det)*a[1][0];
    b[1][0] = - (1/det)*a[0][1];
    b[1][1] = (1/det)*a[0][0];
    // cout << a[0][0] << " " << a[0][1] << "\n";
    // cout << a[1][0] << " " << a[1][1] << "\n";          
    a = b;
    double t = a[1][0];
    a[1][0] = a[0][1];
    a[0][1] = t;
    return a;
}


vector<vector<double>> df(vector<double> X){
    vector<vector<double>> df(2, vector<double> (2));
    df[0][0] = 2;
    df[0][1] = sin(X[1] + 1);
    df[1][0] = cos(X[0]);
    df[1][1] = 1;
    return ober_matr(df);
}


vector<double> operator- (vector<double> a, vector<double> b){
    int i = 0;
    for (auto el : a)
    {
        a[i] = el - b[i];
        i++;
    }
    return a;
}


vector<double> operator* (vector<vector<double>> a, vector<double> b){    
} 


int main() {
    vector < vector <double> > W(2, vector <double> (2) );
    vector<double> a(2), b(2);
    
    // C -= double*matrix*column
return 0;
}