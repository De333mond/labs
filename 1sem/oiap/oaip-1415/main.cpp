#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    a ^= b ^= a ^= b;
}

// "гномья" сортировка

int main()
{
    srand(5);

    const int n = 10;
    int a[n];
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = arr[i] = rand() % 10;
        cout << a[i] << " ";
    }
    cout << endl;


    for (int i = 0; i < n - 1; i++)
        for (int j = i; j >= 0; j--)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
            else break;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";


    int j = 2, i = 1;
    while (i < n)
    {
        if (arr[i - 1] > arr[i]) 
        {
            int t = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = t;
            i--;
            if (i > 0) continue;
        }
        i = j++;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";   
    cout << "\n";

    return 0;
}