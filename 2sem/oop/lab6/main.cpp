#include <iostream>
#include "fraction.h"
#include <ctime>
#include <math.h>
#include <iomanip>
#include <sstream>

using namespace std;

int maxint(int a[], int len)
{
    int max = a[0];
    int maxi = 0;
    for (int i = 0; i < len; i++)
        if (a[i] > max)
        {
            max = a[i];
            maxi = i;
        }
    return maxi;
}

enum Suit
{
    clubs,
    diamonds,
    hearts,
    spades
};
// от 2 до 10 обычные числа
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
/////////////////////////////////////////////////////////////
class card
{
private:
    int number;
    Suit suit;

public:
    card() // конструктор
    {
    }
    void set(int n, Suit s) // установка значения
    {
        suit = s;
        number = n;
    }
    void display(); // показ карты
};
/////////////////////////////////////////////////////////////
void card::display()
{
    if (number >= 2 && number <= 10)
        cout << number;
    else
    {
        switch (number)
        {
        case jack:
            cout << 'J';
            break;
        case queen:
            cout << 'Q';
            break;
        case king:
            cout << 'K';
            break;
        case ace:
            cout << 'A';
            break;
        }
    }
    switch (suit)
    {
    case clubs:
        cout << " Clubs";
        break;
    case diamonds:
        cout << " Diamonds";
        break;
    case hearts:
        cout << " Hearts";
        break;
    case spades:
        cout << " Spades";
        break;
    }
}


class money
{
private:
    long double value;
    string charset = "0123456789";
    bool isFrac = false;
    int fracCount = 0; 

public:
    money() {
        value = 0;
    }
    
    void mstold(string s){
        
        for (int i = 0; i < s.length(); i++)
        {
            if (charset.find(s[i]) != -1){

                value *= 10;
                value += (int)s[i]-48;
                if(isFrac)
                    fracCount++;
            }
            else if (s[i] == '.'){
                isFrac = true;
            }
        }
        
        value = value / pow(10, fracCount);
    }

    long double getValue() {
        return value;
    }

    void setValue(long double v){
        value = v;
    }

    string getStr(){
        const int size = 100; 
        string result;
        stringstream ss;
        
        ss << setprecision(2) << setiosflags(ios_base::fixed) << value;
        
        string t = ss.str();
        int dotpos = t.length();
        
        while ((t[dotpos] != '.') && (dotpos > 0))
            dotpos--;
        
        if (dotpos == 0){
            dotpos = t.length();
        }
        
        int counter = 0;

        for (int i = t.length() - 1; i >= 0; i--)
        {
            if(i < dotpos){
                if ((counter % 3 == 0) && (counter != 0))
                    result = ',' + result;
                counter++;
            }

            result = t[i] + result;
        }
        
        return '$' + result;
    }

    void add(money value){
        this -> value += value.getValue();
    }
};

class safearray
{
private:
    static const int size = 100;
    int arr[size];
public:
    safearray() {
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }

    void set(int value, int index){
        if ((index < size) && (index >= 0)){
            arr[index] = value;
        }
    }

    int get(int index){
        if ((index < size) && (index >= 0)){
            return arr[index];
        }
        else {
            // cout << "[!] Error IndexOutOfRange has accured." << endl;
            throw out_of_range("IndexOutOfRange");
        } 
    }
};



class STACKARRAY 
{
private:
    static const int size = 100;
    int queue[size];
    int tail = 0;
public:
    void put(int value){
        if (tail < size){
            queue[tail++] = value;
        }
        else cout << "[!] Очередь переполнена!" << endl;
    }

    int get(){
        int res = queue[0];
        for (int i = 0; i < tail-1; i++)
            queue[i] = queue[i+1];
        return res;
    }
};


class matrix
{
private:
    int matr[10][10];
    int max1, max2;
public:
    matrix(int a = 10, int b = 10){
        max1 = a; 
        max2 = a;
    }

    void set(int a, int b, int value){
        if (((a >= 0) && (a < max1)) && ((b >= 0) && (b < max2)))
            matr[a][b] = value;
        else 
            throw out_of_range("IndexOutOfRange");
    }

    int get(int a, int b){
        if (((a >= 0) && (a < max1)) && ((b >= 0) && (b < max2)))
            return matr[a][b];
        else 
            throw out_of_range("IndexOutOfRange");
    }
};

int main()
{
    
    srand(time(NULL));

    /*4. Начните с программы, которая позволяет пользователю вводить целые числа, а затем сохранять их в массиве типа int.
    Напишите функцию maxint(), которая, обрабатывая элементы массива один за другим, находит наибольший.
    Функция должна принимать в качестве аргумента адрес массива и количество элементов в нем,
    а возвращать индекс наибольшего элемента. Программа должна вызвать эту функцию, а затем вывести наибольший элемент и его индекс. */
    const int n = 10;

    int arr[n];

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;

    int maxI = maxint(arr, n);
    cout << "4. максимальный элемент массива: " << arr[maxI] << " c индексом: " << maxI << endl;

    /*5.      Начните с класса fraction из упражнений 11 и 12 лабораторной работы 5. Напишите функцию main(),
    которая получает случайные дробные числа от пользователя, сохраняет их в массиве типа fraction,
    вычисляет среднее значение и выводит результат. */

    fraction fracarr[n];
    for (int i = 0; i < n; i++)  
        fracarr[i].setFrac(rand() % 10 + 1, rand() % 10 + 1);
    

    for (int i = 1; i < n; i++)
        fracarr[0].add(fracarr[i]);

    fraction t;
    t.setFrac(n, 1);

    fracarr[0].div(t);

    cout << "5.Среднее значение массива: ";
    fracarr[0].show();
    cout << endl;

    /*6. В игре бридж каждому из игроков раздают 13 карт, таким образом колода расходуется полностью. 
    Модифицируйте программу CARDARAY этой главы так, чтобы после перемешивания колоды она делилась на четыре части по 13 карт каждая. 
    Каждая из четырех групп карт затем должна быть выведена. */

    card deck[4][13];
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 13; j++)   
            deck[i][j].set(j+2, Suit(i));
    
    // shaffle

    for (int i = 0; i < 52; i++)
    {
        int num = rand() %52;
        card t = deck[i/13][i%13];
        deck[i/13][i%13] = deck[num/13][num%13];
        deck[num/13][num%13] = t;
    }

    for (int i = 0; i < 4; i++)
    {
        cout<< i+1 << " колода карт: \n";
        
        for (int j = 0; j < 13; j++)
        {
            cout << "\t";
            deck[i][j].display(); 
            cout << endl;
        }
    }
    
    
    /*7. 
    long double имеет точность 19 цифр, 
    поэтому мы можем использовать его как базисный для класса money, 
    даже используя плавающую точку. Однако нам нужно будет добавить возможность ввода и вывода денежных значений с предшествующим 
    им знаком доллара и разделенными запятыми группы по три числа: так проще читать большие числа. 
    Первым делом при разработке такого класса напишем метод mstold(), который принимает денежную строку, то есть строку, 
    представляющую собой некоторое количество денег типа 
    “$123.456.789.00” в качестве аргумента и возвращает эквивалентное ее значению число типа long double. 
    Вам нужно будет обработать денежную строку как массив символов и, просматривая ее символ за символом, 
    скопировать из нее только цифры (0-9) и десятичную точку в другую строку. Игнорируется все остальное, включая знак доллара и запятые.
    Затем вы можете использовать библиотечную функцию _atold() (заметим, что здесь название функции начинается с 
    символа подчеркивания — заголовочные файлы STDLIB.H или МАТН.Н) для преобразования новой строки к числу типа long double. 
    Предполагаем, что денежное значение не может быть отрицательным. Напишите функцию main() для проверки метода mstold(), 
    которая несколько раз получает денежную строку от пользователя и выводит соответствующее число типа long double. 

    */

    money mon;

    cout << "$123,123,123.345,345 = "; 
    mon.mstold("$123,123,123.345,345");
    cout << setprecision(19) << mon.getValue() << endl;


    /*Безопастный массив*/

    safearray safe;

    for (int i = 0; i < 150; i+= 10)
    {
        safe.set(i,i);
        try
        {
            cout << safe.get(i) << endl;
        }
        catch(const std::exception& e)
        {
            cout << e.what() << '\n';
        }
    }
    

    /*9. Очередь*/

    STACKARRAY st;
    
    for (int i = 0; i < 10; i++)
        st.put(i);
    

    for (int i = 0; i < 10; i++)
    {
        cout << st.get() << endl;
    }
    

    matrix m = matrix(5,5);

    /*Класс безопастная матрица*/
    for (int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            m.set(i, j, i+j);
    
    for (int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
        {
            try
            {
                cout << m.get(i, j) << endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }    
    
    /*11. класс money метод getStr */

    money mon1;
    long double ld = 12345234523.23;
    mon1.setValue(ld);
    cout << "11. " << mon1.getStr() << endl;
    
    /*12. не стал создавать второй такой же класс, просто добавил метод add в существующий*/

    money m1, m2;
    m1.mstold("$1,200.50");
    m2.setValue(1300.50);
    m1.add(m2);
    cout << "12. m1 + m2= " << m1.getStr() << endl;
    return 0;
}