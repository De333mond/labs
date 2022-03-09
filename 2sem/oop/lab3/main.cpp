#include <iostream>
#include <cmath>

using namespace std;


struct Date
{
    int day, month, year;
};

ostream& operator << (ostream& os, Date& a){
    return os << a.day << "/" << a.month << "/" << a.year;
}

istream& operator >> (istream& is, Date& a){
    char trash;
    return is >> a.day >> trash >> a.month >> trash >> a.year;
}

enum etype { laborer, secretary, manager, accountant, executive, researcher }; 

struct employee
{
    int number;
    float fee;
    Date date;
    etype type;
};

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

struct time {

    int seconds, minutes, hours;
    long getTotalSecs(){
        return hours*3600 + minutes*60 + seconds; 
    }

    void setfs(int s){
        seconds = s % 60;
        minutes = (s / 60) % 60;
        hours = s / 3600; 
    }
};

istream& operator >>(istream& is, time& a){
    return is >> a.hours >> a.minutes >> a.seconds;
}

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

    void setfd(double p){
        pound = (int)p;
        pence = (int)((p-pound)*240);
        normalize();
    }

    void normalize(){
        shilling += pence / 12;
        pence = pence % 12;
        pound += shilling / 20;
        shilling = shilling % 20;
    }
};

ostream& operator<< (ostream& os, Pound& a){
    return os << "₤" << a.pound << "." << a.shilling << "." << a.pence;
}

int main()
{

    /* 4. Создайте структуру с именем employee, содержащую два поля:
        номер сотрудника типа int
        величину его пособия в долларах типа float.
        Запросите с клавиатуры данные о трех сотрудниках, сохраните их в трех структурных переменных типа
        employee и выведите информацию о каждом из сотрудников на экран. */
    employee emps[3];
    
    for (int i = 0; i < 3; i++)
    {
        cout << "Введите номер и величину пособия " << i + 1<< " сотрудника: ";
        cin >> emps[i].number >> emps[i].fee;
    }
    
    for (int i = 0; i < 3; i++)
        cout << i + 1 << "й сотрудник имеет " << emps[i].number << " номер и его пособие ссоставляет : " << emps[i].fee << endl;
    
    

    /* 5. Создайте структуру типа date, содержащую три поля типа int: месяц, день и год. 
    Попросите пользователя ввести день, месяц и год в формате 31/12/2002, сохраните введенное значение в 
    структурной переменной, а затем извлеките данные из этой переменной и выведите их на экран в том же формате, 
    в каком они вводились. */
    Date dt;
    char trash;
    
    cout << "Введите дату в формате dd / mm / yyyy: ";
    cin >> dt.day >> trash >> dt.month >> trash >> dt.year;
    cout << "Введенная дата: " << dt << endl;
    

    char ch;
    //6. Вывод перечисления через switch
    
    etype tp;
    cout << "Введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher): ";
    cin >> ch;
    switch (ch)
    {
    case 'l':
        tp = laborer;
        break;
    
    case 's':
        tp = secretary;
        break;
    
    case 'm':
        tp = manager;
        break;
    
    case 'a':
        tp = accountant;
        break;
    
    case 'e':
        tp = executive;
        break;
    
    case 'r':
        tp = researcher;
        break;
    } 

    cout << "Полное названре должности: ";

    switch (tp)
    {
    case 0:
        cout << "laborer" << endl;
        break;
    
    case 1:
        cout << "secretary" << endl;
        break;
    
    case 2:
        cout << "manager" << endl;
        break;
    
    case 3:
        cout << "accountant" << endl;
        break;
    
    case 4:
        cout << "executive" << endl;
        break;
    
    case 5:
        cout << "researcher" << endl;
        break;
    }
    


    /*7. модифицировать пункт 4 полями date и etype*/

    for (int i = 0; i < 3; i++)
    {
        cout << "Введите номер, величину пособия, дату приема и первую букву дожности " << i+1 << " сотрудника: ";
        cin >> emps[i].number >> emps[i].fee
            >> emps[i].date >> ch;
        switch (ch)
           {
        case 'l':
            emps[i].type = laborer;
            break;
        
        case 's':
            emps[i].type = secretary;
            break;
        
        case 'm':
            emps[i].type = manager;
            break;
        
        case 'a':
            emps[i].type = accountant;
            break;
        
        case 'e':
            emps[i].type = executive;
            break;
        
        case 'r':
            emps[i].type = researcher;
            break;
        } 
        }
    
    for (int i = 0; i < 3; i++){
        cout << i+1 << "й сотрудник: " << endl;
        cout << "\t" << "Номер: " << emps[i].number << "\n";
        cout << "\t" << "Пособие: " << emps[i].fee << "\n";
        cout << "\t" << "Дата приема: " << emps[i].date << "\n";
        cout << "\t" << "Должность: ";

        switch (emps[i].type)
        {
        case 0:
            cout << "laborer" << endl;
            break;
            
        case 1:
            cout << "secretary" << endl;
            break;
        
        case 2:
            cout << "manager" << endl;
            break;
        
        case 3:
            cout << "accountant" << endl;
            break;
        
        case 4:
            cout << "executive" << endl;
            break;
        
        case 5:
            cout << "researcher" << endl;
            break;
        }

    }
    

    //8. Сложение двух дробей. Использовать структуру для хранения.

    
    fraction a, b;

    cout << "Введите первую дробь: ";
    cin >> a;
    cout << "Введите вторую дробь: ";
    cin >> b;
    a = a + b;
    cout << "Ответ: " << a << endl;
    

    /*9. Создайте структуру с именем time. Три ее поля, имеющие тип int. 
    будут называться hours, minutes и seconds. 
    Напишите программу, которая просит пользователя ввести время в формате часы, минуты, секунды. 
    Можно запрашивать на ввод как три значения сразу, так и выводить для каждой величины отдельное приглашение. 
    Программа должна хранить время в структурной переменной типа time и выводить количество секунд в введенном времени, 
    определяемое следующим образом: long totalsecs = t1.hours*3600 + t1 minutes*60 + t1.seconds*/  

    time t;
    cout << "Введите время: ";
    cin >> t;
    cout << " total seconds: " << t.getTotalSecs() << endl;

    /*10. Создайте структуру с именем sterling, хранящую денежные суммы в старой английской системе. 
    Поля структуры могут быть названы pounds, shillings и pence и иметь тип int. 
    Программа должна запрашивать у пользователя значение денежной суммы в новых десятичных фунтах 
    затем переводить эту сумму в старую систему, сохранять переведенное значение в переменной типа sterling 
    и выводить на экран полученную сумму в фунтах, шиллингах и пенсах. */
    
    Pound p;
    double dPound;
    cout << "Введите сумму в новом стиле: ";
    cin >> dPound;
    p.setfd(dPound);
    cout << "Ответ: " << p << endl; 
    

    /*11. Используя структуру time из упражнения 9, напишите программу, 
    которая получает от пользователя два значения времени в формате 12:59:59, 
    сохраняет их в переменных типа struct time, затем переводит оба значения в секунды, 
    складывает их, переводит сумму в исходный формат, сохраняет его в переменной типа time
    и выводит полученный результат на экран в формате 12:59:59. */
    
    time t1,t2;
    cout << "Введите первое значение времени в формате 12:59:59: ";
    cin >> t1;
    cout << "Введите второе значение времени в формате 12:59:59: ";
    cin >> t2;

    t1.setfs(t1.getTotalSecs() + t2.getTotalSecs());

    cout << t1.hours << ":" << t1.minutes << ":" << t1.seconds << endl;

    // 12. Калькулятор для дробей
    
    fraction f1,f2;
    int x = 1;
    bool err;
    char op;
    while (x == 1)
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
        cin >> x; 
    }

    return 0;
}