#include <iostream>
#include <time.h> 
#include <fstream>
using namespace std;


void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

void qsort(int *a, int L, int R)
{
    int l = L, r = R;
    int piv = a[(l + r) / 2];

    while (l <= r)
    {
        while (a[l] < piv)
            l++;
        while (a[r] > piv)
            r--;
        if (l <= r)
            swap(a[l++], a[r--]);
    }
    if (L < r)
        qsort(a, L, r);
    if (l < R)
        qsort(a, l, R);
}

int main() {

    ofstream out;
    out.open("C:\\Users\\vladb\\Desktop\\labs-master\\labs\\oaip-18\\qsort.txt");

    srand(time(NULL));


    for (int n = 1000; n <= 30000; n += 1000)
    {
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = rand() % 2000 - 1000;
        
        // sorting
        clock_t start = clock();
        qsort(a, 0, n-1);
        clock_t end = clock();
        // end of sorting
        double secs = (double)(end - start ) / CLOCKS_PER_SEC; 
        out << n << "-" << secs << endl; 
        cout << n << endl;
    
    }
    
    out.close();

    return 0;
}
