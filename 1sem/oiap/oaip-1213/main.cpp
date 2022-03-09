#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    a ^= b ^= a ^= b;
}

// сортировка выбором

int main() {

    const int n = 10;
    int a[n];
    
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10;
        cout << a[i] << " ";
    }
    cout << endl;   

    // using for
    for (int i = 0; i < n-1; i++)
    {
        int min = 10000;
        int min_i;

        for (int j = i; j < n; j++)
        {
            if (a[j] < min) {
                min = a[j];
                min_i = j;
            }
        }

        if (i != min_i) 
            swap (a[i], a[min_i]);
        
    }
    
    // show
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n\n";


    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10;
        cout << a[i] << " ";
    }
    cout << endl;   

    // using while
    int i = 0; 
    while (i < n -1)
    {
        int min = 10000;
        int min_i;

        for (int j = i; j < n; j++)
        {
            if (a[j] < min) {
                min = a[j];
                min_i = j;
            }
        }

        if (i != min_i) 
            swap (a[i], a[min_i]);
        
        i++;
    }
    
    // show
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;


    return 0;
}