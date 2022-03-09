#include <iostream>

using namespace std;
// сортировка вставками
int main()
{
    srand(2);

    const int n = 10;
    int a[n];

    //fill and show
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10;
        cout << a[i] << " ";
    }
    cout << endl;

    //sorting using for
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int j;
        for (j = i; (j > 0) && (a[j - 1] > x); j--)
            a[j] = a[j - 1];
        a[j] = x;
    }

    //show after sorting
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n\n";

    //fill and show
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10;
        cout << a[i] << " ";
    }
    cout << endl;

    // sorting using while
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int j = i;
        while ((j > 0) and (x < a[j - 1]))
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = x;
    }

    //show after sorting
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}