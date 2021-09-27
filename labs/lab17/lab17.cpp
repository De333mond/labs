#include <iostream>
#include <ctime>

using namespace std;

void num1() {
    cout << "1. Дан массив размера N и целые числа K и L (1 ≤ K ≤ L ≤ N). Найти среднее арифметическое элементов массива с номерами от K до L включительно." << endl;
     
    const int n = 20;
    int arr[n];

    for (int i = 0; i < n; i++) //fill array
    {
        arr[i] = rand()%101;
        cout << arr[i] << ' ';
    }
    cout << endl;
    
    
    int k,l;

    cin >> k >> l;  
    
    int sum = 0;

    for (int i = k; i <= l; i++)
    {
        sum += arr[i-1];
    }
    
    cout << (double)sum/(l-k+1)  << endl;
}

void num2() {
    
    cout << "2. Дан целочисленный массив размера N, не содержащий одинаковых чисел. Проверить, образуют ли его элементы арифметическую прогрессию. Если образуют, то вывести разность прогрессии, если нет — вывести 0." << endl;

    const int n = 5;
    int a[n];
    bool correct = true;
    int d = 0;
    int prev_d = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i > 0) {
            d = a[i] - a[i-1];
            if (prev_d == 0){
                prev_d = d;
            }
            else if (d != prev_d) {
                correct = false;
            }
        }
    }

    if (correct) cout << d << endl;
    else cout << "0" << endl;

}

void num3() {
    //3. Дан массив A размера N. Найти минимальный элемент из его элементов с четными номерами: A2, A4, A6,

    const int n = 10;
    int a[n];

    for (int i = 0; i < n; i++)
        {
            a[i] = rand()%16;
            cout << a << endl;
            
        }

    int min = 1000000;

    for (int i = 0; i < n; i+=2)
        if (a[i] < min) 
            min = a[i];
    cout << min << endl;
       
}

void num4() {
    // 4. Дан массив размера N. Найти номер его последнего локального максимума 
    // (локальный максимум — это элемент, который больше любого из своих соседей).

    const int n = 20;
    int a[n];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand()%20;
        cout << a[i] << "-" << i << endl;
        
        if ((i > 1) & ((a[i-1] > a[i-2]) & (a[i-1] > a[i])))
        {
            index = i-1;
        }  
    }

    cout << index << endl;

}

void num5() {
    // 5. Дан целочисленный массив размера N, содержащий ровно два одинаковых элемента.
    // Найти номера одинаковых элементов и вывести эти номера в порядке возрастания

    const int n = 10;
    int a[n] = {1, 8, 6, 12, 20, 14, 6,5,9,10}; 

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[i] == a[j]){
                cout << i << " " << j << endl;
            }
        }
         
    }
}

int main()
{
    srand(time(nullptr));
    
    //num1();
    //num2();
    //num3();
    //num4();
    num5();
    return 0;
}