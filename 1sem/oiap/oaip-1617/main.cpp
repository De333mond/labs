#include <iostream>

using namespace std;

// быстрая сортировка
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

int main()
{

    srand(1);

    const int n = 10;
    int a[n];

    for (int i = 0; i < n; i++)
        a[i] = rand() % 10;

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    qsort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}