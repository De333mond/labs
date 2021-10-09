#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int t = a; 
    a = b;
    b = t;
}

int main() {

    const int n = 20;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        //arr[i] = rand()%20;
        arr[i] = 20-i;
        cout << arr[i] << " ";
    }

    cout << endl;

    const float k = 1.247;
    int step = n-1;

    while (step >= 1) {
        for (int j = 0; j < n-step; j++)
        {
            if (arr[j] > arr[j+step]) 
                swap(arr[j], arr[j+step]);
        }
        step /= k;
    }
    
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}