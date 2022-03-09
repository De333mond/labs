#include <iostream>

using namespace std;

struct Pound{
    int pound, shilling, pence;
  
    Pound(){
        pound = shilling = pence = 0;
    }
    
    Pound(int pd, int sh, int pc){
        this->pound = pd;
        this->shilling = sh;
        this->pence = pc;
        normalize();
    }

    void normalize(){
        shilling += pence / 12;
        pence = pence % 12;
        pound += shilling / 20;
        shilling = shilling % 20;
    }
};

Pound operator+ (Pound a, Pound b){
    a.pound += b.pound;
    a.shilling += b.shilling;
    a.pence += b.pence;
    a.normalize();
    return a;
}

Pound operator- (Pound a, Pound b){
    a.pound -= b.pound;
    a.shilling -= b.shilling;
    a.pence -= b.pence;

    if (a.pound > 0 && a.shilling < 0){
        a.pound--;
        a.shilling += 20;
    }
    
    if (a.shilling > 0 && a.pence < 0){
        a.shilling--;
        a.pence += 12;
    }
    else if (a.pound > 0){
        a.pound--;
        a.shilling += 19;
        a.pence += 12;
    }
    
    return a;
}

Pound operator* (Pound a, int b){
    a.pound *= b;
    a.shilling *= b;
    a.pence *= b;
    a.normalize();
    return a;
}

ostream& operator<< (ostream& os, Pound& a){
    return os << "₤" << a.pound << "." << a.shilling << "." << a.pence;
}

istream& operator>> (istream& is, Pound& a){
    return is >> a.pound >> a.shilling >> a.pence; 
}

struct fraction
{
    int numerator, denumerator;
    
    fraction(){
        numerator = denumerator = 0;
    }

    fraction(int n, int d){
        this->numerator = n;
        this->denumerator = d;
    }

};

fraction operator+ (fraction a, fraction b){
    a.numerator = (a.numerator*b.denumerator + a.denumerator* b.numerator);
    a.denumerator = (a.denumerator * b.denumerator);
    return a;
}

fraction operator- (fraction a, fraction b){
    a.numerator = (a.numerator*b.denumerator - a.denumerator* b.numerator);
    a.denumerator = (a.denumerator * b.denumerator);
    return a;
}

fraction operator* (fraction a, fraction b){
    a.numerator = (a.numerator*b.numerator);
    a.denumerator = (a.denumerator * b.denumerator);
    return a;
}

fraction operator/ (fraction a, fraction b){
    a.numerator = (a.numerator*b.denumerator);
    a.denumerator = (a.denumerator * b.numerator);
    return a;
}

ostream& operator<< (ostream& os, fraction& a){
    return os << a.numerator << "\\" << a.denumerator;
}

istream& operator>> (istream& is, fraction& a){
    char trash;
    return is >> a.numerator >> trash >> a.denumerator; 
}

int main() {
    
    // 5. Изобразить в консоли пирамиду из n линий.

    int n = 10;
    int width = 1 + (n-1)*2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < width/2-i; j++)
            cout << " " ;

        for (int j = 0; j < 1+i*2; j++)
            cout << "*" ;
    
        cout << "\n";
    }

    // 6. Цикличесоке вычисление факториала

    int a = 1,b;
    while (a != 0) {
        cout << "6. Введите число для вычисдения факториала: ";
        cin >> b;
        a = 1;
        for (int i = 1; i <= b; i++)
            a *= i;
        cout << "Ответ: " << a << " Продолжить? (1/0)" << endl;
        cin >> a;        
    }

    // 7. Расчитать сумму по начальному вкладу, проценту и сроку.

    int y;
    float base, percent;
    cout << "7. Введите начальную сумму, процент и количество лет: ";
    cin >> base >> percent >> y;
    percent = percent/100 + 1;
    for (int i = 0; i < y; i++)
        base *= percent;

    cout << "Ответ: " << base << endl;    

    // 8. циклически сложить две суммы в фунатах

    Pound p1, p2;

    a = 1;
    while (a != 0)
    {
        cout << "8. Введите первую сумму: ";
        cin >> p1;
        
        cout << "Введите вторую сумму: ";
        cin >> p2;

        p1 = p1 + p2;
        cout << "Ответ: " << p1 << " Продолжить? (1/0) ";
        cin >> a;
    }

    // 9. Посчитать количество гостей
    
    int chairs, people;
    cout << "9. Введите количество гостей и стульев: "; 
    cin >> people >> chairs;
    a = 1;
    for (int i = 0; i < chairs; i++)
        a *= people - i;
    
    cout << "Ответ: " << a << endl;

    // 10. Посчитать количество лет для накопления вклада
    float need;
    cout << "10. Введите начальную сумму, конечную и процент: ";
    cin >> base >> need >> percent;
    y = 0;
    percent = 1 + percent/100;
    while (base < need){
        base *= percent;
        y++;
    }
    cout << "Через " << y << " лет вклад будет составлять: " << base << endl;
    
    // 11. Калькулятор для фунтов

    char op;
    bool err = false;
    a = 1;
    while (a != 0){        
        err = false;
        cout << "11. Введите выражение: "; 
        cin >> p1 >> op >> p2.pound;
        if (op != '*')
            cin >> p2.shilling >> p2.pence;

        switch (op)
        {
        case '+':
            p1 = p1 + p2;
            break;
        
        case '-':
            p1 = p1 - p2;
            break;
        
        case '*':
            p1 = p1 * p2.pound;
            break;
        
        default:
            cout << "Невернео выражение.";
            err = true;
            break;
        }

        if (!err) 
            cout << "Ответ: " << p1;
        cout << " Продолжить ? (1/0) ";
        cin >> a; 
    }
    
    // 12. Калькулятор для дробей
    
    a = 1;
    fraction f1,f2;
    while (a == 1)
    {
        err = false;
        cout << "12. Введите выражение: ";
        cin >> f1 >> op >> f2;

        switch (op)
        {
        case '+':
            f1 = f1 + f2;
            break;
        
        case '-':
            f1 = f1 - f2;
            break;
        
        case '*':
            f1 = f1 * f2;
            break;
        
        case '/':
            f1 = f1 / f2;
            break;
        
        case '\\':
            f1 = f1 / f2;
            break;
        
        default:
            cout << "Невернео выражение.";
            err = true;
            break;
        }

        if (!err) 
            cout << "Ответ: " << f1;
        cout << " Продолжить ? (1/0) ";
        cin >> a; 
    }
    
return 0;
}