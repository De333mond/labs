    #include <iostream>

    using namespace std;

    struct time {

        time(){
            hours = minutes = seconds = 0;
        }

        time(int h, int m, int s){
            this->hours = h;
            this->minutes = m;
            this->seconds = s;
        }

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

    ostream& operator <<(ostream& os, time& a){
        return os << a.hours << ":" << a.minutes << ':' << a.seconds;
    }

    long int hms_to_secs(int h, int m, int s){
        return h*3600+m*60+s;
    }

    long int time_to_sec(time t){
        return t.hours*3600 + t.minutes*60 + t.seconds; 
    }

    time secs_to_time(long int s){
        time t;
        t.seconds = s % 60;
        t.minutes = (s / 60) % 60;
        t.hours = s / 3600;
        return t; 
    }

    double power(char a, int p = 2){
        double res = 1;
        for (int i = 0; i < p; i++)
            res*=a;
        return res;
    }

    double power(int a, int p = 2){
        double res = 1;
        for (int i = 0; i < p; i++)
            res*=a;
        return res;
    }

    double power(long a, int p = 2){
        double res = 1;
        for (int i = 0; i < p; i++)
            res*=a;
        return res;
    }

    double power(float a, int p = 2){
        double res = 1;
        for (int i = 0; i < p; i++)
            res*=a;
        return res;
    }

    void swap(int& a,int& b){
        int t = a;
        a = b;
        b = t;
    }

    void swap(time& a, time& b){
        time t;
        t = a;
        a = b; 
        b = t;
    }

    int gloabal_counter = 0;

    void f(){
        static int static_local_counter;
        gloabal_counter ++;
        static_local_counter++;
        cout << "Вызов функции. gloabal_counter = " << gloabal_counter << " static_local_counter = " << gloabal_counter << endl;
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

    Pound PfI(int p, int s, int pc){
        Pound t;
        t.pound = p;
        t.shilling = s;
        t.pence = pc;
        return t;
    }

    Pound sum(Pound a, Pound b){
        a.pound += b.pound;
        a.shilling += b.shilling;
        a.pence += b.pence;
        a.normalize();
        return a;
    }

    void show(Pound a){
        cout << "₤" << a.pound << "." << a.shilling << "." << a.pence;
    }

    struct fraction
    {
        int numerator, denumerator;
        
        fraction(){
            numerator = denumerator = 0;
        }

        fraction(int n, int d){
            numerator = n;
            denumerator = d;
        }

    };

    fraction fadd (fraction a, fraction b){
        a.numerator = (a.numerator*b.denumerator + a.denumerator* b.numerator);
        a.denumerator = (a.denumerator * b.denumerator);
        return a;
    }

    fraction fsub (fraction a, fraction b){
        a.numerator = (a.numerator*b.denumerator - a.denumerator* b.numerator);
        a.denumerator = (a.denumerator * b.denumerator);
        return a;
    }

    fraction fmul (fraction a, fraction b){
        a.numerator = (a.numerator*b.numerator);
        a.denumerator = (a.denumerator * b.denumerator);
        return a;
    }

    fraction fdiv (fraction a, fraction b){
        a.numerator = (a.numerator*b.denumerator);
        a.denumerator = (a.denumerator * b.numerator);
        return a;
    }

    ostream& operator<< (ostream& os, fraction& a){
        return os << a.numerator << "\\" << a.denumerator;
    }

    int main() {

        /*5. Циклический перевод введенного времени в секунды*/

        int a = 1;
        int h,m,s;
        while (a == 1){
            cout << "Введите время: ";
            cin >> h >> m >> s;
            cout << "Время в секундах: " << hms_to_secs(h,m,s) << " Продолжить? (1/0)";
            cin >> a; 
        }

        /*6. Модифицируйте программу, описанную в упражнении 11 предыдущей лабораторной работы 
        «Структуры», складывающую два структурных значения типа time. Теперь программа должна включать в
        себя две функции. Первая, time_to_secs(), принимает в качестве аргумента значение типа time
        и возвращает эквивалентное значение в секундах типа long. Вторая, secs_to_time(), в качестве 
        аргумента принимает число секунд, имеющее тип long, а возвращает эквивалентное значение типа 
        time. */

        time t1,t2;
        
        cout << "Введите первое значение времени в формате 12:59:59: ";
        cin >> t1;
        cout << "Введите второе значение времени в формате 12:59:59: ";
        cin >> t2;

        t1 = secs_to_time(time_to_sec(t1)+time_to_sec(t2));

        cout << "Ответ: " << t1 << endl;
            

        /*7. Взяв в качестве основы функцию power() из упражнения 2, работающую только со значением
        типа double, создайте перегруженные функции с этим же именем, принимающими в качестве 
        аргумента значения типа char, int, long и float. Напишите программу, вызывающую функцию 
        power() со всеми возможными типами аргументов. */

        char ch = 16;
        int in = 16;
        long lg = 16;
        float fl = 16;
        cout << "power(ch) = " << power(ch) << endl;
        cout << "power(in) = " << power(in) << endl;
        cout << "power(lg) = " << power(lg) << endl;
        cout << "power(fl) = " << power(fl) << endl;

        /*8. Напишите функцию с именем swap(), обменивающую значениями два своих аргумента типа int 
        (обратите внимание, что изменяться должны значения переменных из вызывающей программы, 
        а не локальных переменных функции). Выберите способ передачи аргументов. Напишите вызывающую
        программу main(), использующую данную функцию. */

        int x = 2, y = 3;

        cout << "x = " << x << " y = " << y << endl;
        swap(x,y);
        cout << "x = " << x << " y = " << y << endl;

        /*9 .Переработайте программу из упражнения 8 так, чтобы функция swap() принимала в
        качестве аргументов значения типа time (см. упражнение 6) */

        t1 = time(1,20,40);
        t2 = time(0,45,23);

        cout << "t1 = " << t1 << " t2 = " << t2 << endl;
        swap(t1,t2);
        cout << "t1 = " << t1 << " t2 = " << t2 << endl;


        /*10. Напишите функцию, которая при каждом вызове будет выводить на экран количество раз, 
        которое она вызывалась ранее. Напишите программу, которая будет вызывать данную функцию не менее
        10 раз. Попробуйте реализовать данную функцию двумя различными способами: с использованием 
        глобальной переменной и статической локальной переменной для хранения числа вызовов функции. 
        Какой из способов предпочтительней? 
        Почему для решения задачи нельзя использовать обычную локальную переменную? */

        for (int i = 0; i < 10; i++)
            f();


        /*11. Необходимо разработать три функции. 
        Первая из них должна получать от пользователя число фунтов, шиллингов и пенсов и возвращать 
        соответствующее значение типа sterling. 
        
        Вторая функция должна принимать в качестве аргументов два значения типа sterling, 
        складывать их и возвращать значение, также имеющее тип sterling. 
        
        Третья функция должна принимать аргумент типа sterling и выводить его значение на экран. */
        
        Pound p1 = Pound(1,2,5), p2 = PfI(3,2,3);
        cout << "p1 = ";
        show(p1); 
        cout << " p2 = "; 
        show(p2); 
        cout << endl;
        p1 = sum(p1,p2);
        cout << "Sum = ";
        show(p1);
        cout << endl;

        /*12. Модифицируйте калькулятор, созданный в упражнении 12 лабораторной 
        работы 2 «Структуры», так, чтобы каждая арифметическая операция выполнялась 
        с помощью функции. Функции могут называться fadd(), fsub(), fmul() и fdiv(). 
        Каждая из функций должна принимать два структурных аргумента типа fraction и 
        возвращать значение того же типа. */

        fraction f1 = fraction(1,2), f2 = fraction(3,4);
        fraction t;
        
        t = fadd(f1,f2);
        cout << f1 << " + " << f2 << " = " << t << endl;
        
        t = fsub(f1,f2);
        cout << f1 << " - " << f2 << " = " << t << endl;
        
        t = fmul(f1,f2);
        cout << f1 << " * " << f2 << " = " << t << endl;
        
        t = fdiv(f1,f2);
        cout << f1 << " / " << f2 << " = " << t << endl;


    return 0;
    }