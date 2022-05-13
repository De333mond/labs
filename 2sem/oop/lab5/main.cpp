#include <iostream>
#include "fraction.h"

using namespace std;

/*5. Взяв в качестве основы структуру из задачи 5 лабораторной работы 2, создайте класс date. 
Его данные должны размещаться в трех полях типа int: month, day и year. Метод класса getdate() 
должен принимать значение для объекта в формате 12/31/02, а метод showdate() - выводить данные на экран. */

class Date
{
private:
    int day, month, year; 
public:
    void setDate(int day, int month, int year){
        this -> day = day;
        this -> month = month;
        this -> year = year;
    }    

    void showDate(){
        cout << day << "/" << month << '/' << year;
    }
};

enum etype { laborer, secretary, manager, accountant, executive, researcher }; 

class employee
{
private:
    int num;
    float fee;
    Date date;
    etype type;
public:
    void setValues(int num, float fee, Date date, char letter){
        this -> num = num;
        this -> fee = fee;
        this -> date = date;

        switch (letter)
        {
        case 'l':
            type = laborer;
            break;
        
        case 's':
            type = secretary;
            break;
        
        case 'm':
            type = manager;
            break;
        
        case 'a':
            type = accountant;
            break;
        
        case 'e':
            type = executive; 
            break;
        
        case 'r':
            type = researcher; 
            break;
        } 
    }

    void showValues() {
        cout << "Номер: " << num << " Пособие: " << fee << " Дата приема: ";
        date.showDate();
        cout << " Должность: ";
        
        switch (type)
            {
            case 0:
                cout << "laborer";
                break;
            case 1:
                cout << "secretary";
                break;
            case 2:
                cout << "manager";
                break;
            case 3:
                cout << "accountant";
                break;
            case 4:
                cout << "executive";
                break;
            case 5:
                cout << "researcher";
                break;
            }
            cout << endl;
    }

};

/*7. Создайте класс angle, включающий следующие три поля: 
    типа int для числа градусов, 
    типа float для числа минут и 
    типа char для указания направления (N, S, Е или W). 
Создайте метод, позволяющий ввести координату точки, направление, в котором она измеряется, 
и метод, выводящий на экран значение этой координаты, например 179°59.9' Е. К
роме того, напишите конструктор, принимающий три аргумента. 
Напишите функцию mainQ, которая сначала создает переменную с помощью трехаргументного конструктора и выводит ее значение на экран, 
а затем циклически запрашивает пользователя ввести значение координаты и отображает введенное значение на экране.  */

class angle
{
private:
    int degree; 
    float minute; 
    char direction;

public:
    angle(int degree, float minute, char direction){
        this -> degree = degree;
        this -> minute = minute;
        this -> direction = direction;
    }

    angle(){
        degree = 0;
        minute = 0;
        direction = '-';
    }
    
    void setPoint(int degree, float minute, char direction){
        this -> degree = degree;
        this -> minute = minute;
        this -> direction = direction;
    }

    void showPoint(){
        cout << degree << '*' << minute << "' " << direction << " "; // "*" потому что градусы не выводятся(
    }
    
};

// 8. Создайте класс, одно из полей которого хранит «порядковый номер» объекта
//    В класс следует включить метод, который будет выводить на экран порядковый номер объекта. 
//    Создайте функцию main(), в которой будут созданы три объекта, и каждый объект выведет на экран свой порядковый номер, например: 
//    Мой порядковый номер: 2 и т. п.

class counter
{
private:
    void show(){
        cout << "counter object # " << n << endl; 
    }
    static int global_n;
    int n;
public:
    counter() {
        global_n++;
        n = global_n;
        show();
    }

    int getnumber(){
        return n;
    }
};
int counter::global_n = 0;


/*10. Создайте класс с именем ship. Для задания номера корабля следует использовать механизм из упражнении 8. 
      Для хранения координат используйте два поля типа angle. 
      Разработайте метод, который будет сохранять в объекте данные о корабле, вводимые пользователем, 
      метод, выводящий данные о корабле на экран.*/

class ship
{
private:
    angle a1;
    angle a2;
    static int global_num;
    int num;
public:
    ship() {
        global_num ++;
        num = global_num;
    }

    void setPosition(angle a1, angle a2){
        this -> a1 = a1;
        this -> a2 = a2;
    }

    void show(){
        cout << "Корабль номер " << num << " имеет координаты: \n\t";
        a1.showPoint();
        cout << "\n\t";
        a2.showPoint();
        cout << "\n";
    }

    int getNum() {
        return num;
    }
};

int ship::global_num = 0;

int main() {

    /*6. Расширьте содержание класса employee из задачи 4, включив в него класс date и перечисление etype 
    (см. задачу 6 лабораторной работы 2). Объект класса date будет использоваться для хранения даты приема 
    сотрудника на работу. Перечисление будет использовано для хранения статуса сотрудника: лаборант, секретарь, 
    менеджер и т. д. Последние два поля данных должны быть закрытыми в определении класса employee, как и номер 
    и оклад сотрудника. Вам будет необходимо разработать методы getemploy() и putemploy(), предназначенные 
    соответственно для ввода и отображения информации о сотруднике. Возможно, при создании методов вам понадобится
    ветвление switch для работы с перечисляемым типом etype. Напишите функцию main(), которая попросит пользователя 
    ввести данные о трех сотрудниках, а затем выведет эти данные на экран. */
    
    /*Сделал сразу 6 тк 4 тоже самое по сути*/

    
    employee emps[3];
    int num, d, m, y;
    float fee;
    char letter;
    Date date;
    for (int i = 0; i < 3; i++)
    {
        cout << "Введите данные о " << i + 1 << " сотруднике(номер, пособие, дату приема, первую букву должности): ";
        // cin >> num >> fee >> d >> letter >> m >> letter >> y >> letter;
        num = rand()%30;
        fee = rand()%1000;
        d = rand()%30; 
        m = rand()%12;
        y = 2015 + rand()%4 - 1;
        letter = "lsmaer"[rand()%6];
        date.setDate(d,m,y);
        cout << num << " " << fee << " " << d << " / " << m << " / " << y << " " << letter << endl;
        emps[i].setValues(num, fee, date, letter); 
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "Данные сотрудника номер " << i + 1 << ": ";
        emps[i].showValues();
    }
    cout << endl;
    

    /*7. Создание переменной angle с инициализацией через конструктор и вывод ее.
         Затем тоже самое, только циклично.*/


    int cont = 0;    
    angle Angle = angle(20, 38.05, 'W');
    Angle.showPoint();
       
    do
    {
        if(cont == 1){
           cout << "Введите градусы, минуты и направление: ";
           int d;
           float m;
           char dir;
           cin >> d >> m >> dir;
           Angle.setPoint(d,m,dir);
           Angle.showPoint(); 
        }
        cout << "Продолжить? (1/0) ";
        cin >> cont;
    } while (cont == 1);

    
    /*8. Создайте функцию main(), в которой будут созданы три объекта, и каждый объект выведет на экран свой порядковый номер, например: 
        Мой порядковый номер: 2 и т. п.*/

    counter n1,n2,n3;


    /*9. Напишите функцию main(), которая циклически запрашивает у пользователя ввод пары дробей, затем складывает их и выводит 
    результат на экран. После каждой такой операции программа должна спрашивать пользователя, следует ли продолжать цикл.*/

    fraction f1,f2;

    cont = 1;
    char dumm;
    int n;
    while (cont == 1){
        cout << "Введите первую дробь в формате n/d: ";
        // cin >> n >> dumm >> d;
        n = rand() % 20;
        d = rand() % 20 + 1;
        f1.setFrac(n,d);
        cout << n << ' / ' << d << endl;
        
        cout << "Введите вторую дробь в формате n/d: ";
        // cin >> n >> dumm >> d;
        n = rand() % 20;
        d = rand() % 20 + 1;
        cout << n << ' / ' << d << endl;
        f2.setFrac(n,d);
        
        f1.add(f2);
        cout << "Результат сложения: ";
        f1.show();
        cout << "\nПродолжить? (1/0): ";
        cin >> cont;
    }

    /*10. Напишите функцию mainQ, создающую три объекта класса ship, затем запрашивающую ввод 
    пользователем информации о каждом из кораблей и выводящую на экран всю полученную информацию. */

    ship ships[3];
    int degree;
    float minutes;
    char direction;
    angle a1, a2;
    for (int i = 0; i < 3; i++)
    {
        cout << "Введите первую координату (градусы минуты направление) " << ships[i].getNum() << " корабля: ";
        // cin >> degree >> minutes >> direction;
        degree = rand()%180;
        minutes = rand()%60 + (rand()%1000/1000);
        direction = "NSEW"[rand()%4];
        cout << degree << " " << minutes << " " << direction << endl;
        a1.setPoint(degree, minutes, direction);
        
        cout << "Введите вторую координату (градусы минуты направление) " << ships[i].getNum() << " корабля: ";
        // cin >> degree >> minutes >> direction;
        degree = rand()%180;
        minutes = rand()%60 + (rand()%1000/1000);
        direction = "NSEW"[rand()%4];
        cout << degree << " " << minutes << " " << direction << endl;
        a2.setPoint(degree, minutes, direction);

        ships[i].setPosition(a1, a2);
    }
    
    for (int i = 0; i < 3; i++)
    {
        ships[i].show();
    }
    
    /*11. Модифицируйте калькулятор, созданный в упражнении 12 главы 5 так, чтобы вместо структуры fraction использовался одноименный класс.*/
    
    int x,z,w;
    char op;
    cont = 1;
    string opSet = "+-*/";
    while(cont == 1){

    cout << "11. Введите выражение: ";
    // cin >> x >> dumm >> y >> op >> z >> dumm >> w;
    x = rand() % 20;
    y = rand() % 20 + 1;
    z = rand() % 20;
    w = rand() % 20 + 1;
    op = opSet[rand()%4];
    cout << x << '/' << y << " " << op << " " << z << "/" << w << endl;
    f1.setFrac(x,y);
    f2.setFrac(z,w);

    switch (op)
    {
    case '+':
        f1.add(f2);
        break;
    
    case '-':
        f1.sub(f2);
        break;
    
    case '*':
        f1.mult(f2);
        break;
    
    case '/':
        f1.div(f2);
        break;
    }
    cout << "Результат: ";
    f1.show();
    cout << "\nПродолжить? (1/0) ";
    cin >> cont;
    }

    return 0;
}
