#include <iostream>

using namespace std;

void num1() {

    const int n = 5;

    int a[n] = {1,2,3,4,5}, b[n] = {6,7,8,9,0};


    for (int i = 0; i < n; i++)
    {
        // (a[i], b[i]) = (b[i], a[i]);
        int t = a[i];
        a[i] = b[i];
        b[i] = t;
        }

    cout << "a-array :" << endl;
    
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << "\nb-array :" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    
    cout << "\n----------------" << endl;

}

void num2() {
    const int n = 5;

    int a[n] = {1,2,3,4,5};
    double b[n];

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = 0; j <= i; j++)
        {
            sum += a[j];    
        }
        
        b[i] = (double)sum/(i+1);
    }

    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }

    cout << "\n----------------" << endl;

}


void num3() {
    const int n = 5;

    int a[n] = {1,2,3,4,5};

    int noteven = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0) {
            noteven = a[i];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0) {
            a[i] += noteven;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " "; 
    }

    cout << "\n----------------" << endl;

}

void num4() {
    const int n = 10;

    int a[n] = {6,4,7,4,9,1,4,4,11,6};

    int min = 100000;
    int max = 0;
    int min_index = 0;
    int max_index = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i]; 
            min_index = i;
        }

        if (a[i] > max) {
            max = i;
            max_index = i;
        }
    }

    for (int i = min_index+1; i < max_index; i++)
    {
        a[i]= 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " "; 
    }
    
    cout << "\n----------------" << endl;

}


void num5() {
    const int n = 5;

    int a[n] = {6,2,3,4,5};

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    
     for (int i = 0; i < n; i++)
    {
        cout << a[i] << " "; 
    }
    
    cout << "\n----------------" << endl;

}
int main()
{
    num5();

    return 0;
}