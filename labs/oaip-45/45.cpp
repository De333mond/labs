#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main()
{

    // bouble sorting using do-while

    const int n = 10;
    int arr[n];

    
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 20;

    int count = 0;

    do
    {
        count = 0;
        for (int i = 0; i < n-1; i++)
            if (arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                count++;
            }
    } while (count != 0);


    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    cout << endl;

    
    // bouble sorting using for

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 20;

    for (int i = 0; i < n-1; i++)
    {
        count = 0;
        for (int j = 0; j < n-1; j++)
        {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j + 1]);
                count++;
            }
        }
        if (count = 0) 
            break;
    }
    
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    int a = 0 ;
    cin >> a;
    

    return 0;
}