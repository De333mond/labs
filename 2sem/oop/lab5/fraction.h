#pragma once
#include <iostream> 

/*9. На основе структуры fraction из упражнения 8 главы 4 создайте класс fraction. 
Данные класса должны быть представлены двумя полями: числителем и знаменателем. 
Методы класса должны получать от пользователя значения числителя и знаменателя дроби в форме 3/5 и 
выводить значение дроби в этом же формате. Кроме того, должен быть разработан метод, складывающий значения двух дробей. 
Напишите функцию main(), которая циклически запрашивает у пользователя ввод пары дробей, затем складывает их и выводит 
результат на экран. После каждой такой операции программа должна спрашивать пользователя, следует ли продолжать цикл. 
*/

/* 11. Модифицируйте калькулятор, созданный в упражнении 12 главы 5 так, чтобы вместо структуры fraction использовался одноименный класс. 
    Класс должен содержать методы для ввода и вывода данных объектов, а также для выполнения арифметических операций. 
    Кроме того, необходимо включить в состав класса функцию, приводящую дробь к несократимому виду. 
    Функция должна находить наибольший общий делитель числителя и знаменателя и делить числитель и знаменатель на это значение.*/


class fraction{
private: 
    int denumerator; 
    int numerator; 

public:

    fraction(){
        numerator = 0;
        denumerator = 1;
    }


    void setFrac(int num, int denum){
        numerator = num;
        denumerator = denum;
        lowterms();
    }

    
    void show(){
        lowterms();
        std::cout << numerator << "/" << denumerator;
    }

    int getNumerator(){
        return numerator;
    }

    int getDenumerator(){
        return denumerator;
    }

    void lowterms(){
        int tnum = numerator;
        int tdenum = denumerator;
        
        

        while (abs(tnum-tdenum) != 0)
        {
            if (tnum > tdenum)    
                tnum -= tdenum;
            else tdenum -= tnum;
        }

        numerator /= tdenum;
        denumerator /= tdenum;
    }   

    void add(fraction f){
        this->numerator = (numerator* f.denumerator) + denumerator * f.numerator;
        this->denumerator *= f.denumerator;
    }

    void sub(fraction f){
        this->numerator = (numerator* f.denumerator) - denumerator * f.numerator;
        this->denumerator *= f.denumerator;
    }

    void mult(fraction f){
        numerator = numerator * f.numerator;
        denumerator = denumerator * f.denumerator;
    }

    void div(fraction f){
        numerator = numerator * f.denumerator;
        denumerator = denumerator * f.numerator;
    }
};
    
