#include <iostream>

using namespace std;

class employee
{
private:
    int number;
    float fee;
    date Date; 
    etype type;
public:    
    int getNumber(){
        return number;
    }

    float getFee(){
        return fee;
    }

    void setNumber(int number){
        this->number = number;
    }

    void setFee(float fee){
        this -> fee = fee;
    }

    void setType(char ch){
        switch (ch)
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

    void setDate(date d){
        Date = d;
    }
    void show(){
        cout << "Number: " << number << " fee: " << fee << endl;
    }
};

class date
{
private:
    int year, month, day;
public:
    date(){
        year = month = day;
    }

    date(int year, int month, int day){
        this -> year = year;
        this -> month = month;
        this -> day = day;
    }
    
    void getdate(int year, int month, int day){
        this -> year = year;
        this -> month = month;
        this -> day = day;
    }

    void showdate(){
        cout << day << '/' << month << '/' << year;
    }

};

enum etype { laborer, secretary, manager, accountant, executive, researcher }; 



int main() {

    /*4. Создайте класс employee, используя задачу 4 лабораторной работы 2. Класс
    должен включать поле типа int для хранения номера сотрудника и поле типа float для
    хранения величины его оклада. Методы класса должны позволять пользователю вводить и
    отображать данные класса. Напишите функцию main(), которая запросит пользователя
    ввести данные для трех сотрудников и выведет полученную информацию на экран. */
    int num;
    float fee; 
    employee emps[3];  
    
    for (int i = 0; i < 3; i++)
    {
        cout << "Введиете номер и пособие " << i+1 << " сотрудника: ";
        cin >> num >> fee;
        emps[i].setNumber(num);
        emps[i].setFee(fee);
    }

    for (int i = 0; i < 3; i++)
    {
        cout << i+1 <<"й сотрудник - ";
        emps[i].show();
    }
    
    

return 0;
}