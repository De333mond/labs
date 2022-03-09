#include <iostream>

using namespace std;
// сортировка шелла
int main() {

    srand(4);

    const int n = 20;
    int a[n];

    // fill
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10;
        cout << a[i] << " ";
    }
    cout << endl;   

    
    // using for

    for (int step = n / 2; step > 0; step /= 2) {
        for (int i = step; i <= n; i++)
            for(int j = i; j >= step; j -= step)
                if (a[j-step] > a[j])
                    a[j] ^= a[j-step] ^= a[j] ^= a[j-step];
    }

    // show 
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n\n";

    // fill and show
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10;
        cout << a[i] << " ";
    }
    cout << endl;

    // using while

    int step = (int)n/2;
    while (step >= 1) {
         for (int i = step; i <= n; i++)
            for(int j = i; j >= step; j -= step)
                if (a[j-step] > a[j])
                    a[j] ^= a[j-step] ^= a[j] ^= a[j-step];
        step /= 2;
    }
    
    
    // show 
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n\n";

    return 0;
}