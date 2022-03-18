#include <iostream>


using namespace std;

class fraction
{

private:
    int numerator;
    int denumerator;

public:
    fraction()
    {
        numerator = 0;
        denumerator = 1;
    }

    fraction(int n, int d)
    {
        numerator = n;
        denumerator = d;
        lowterms();
    }

    void show()
    {
        lowterms();
        cout << numerator << "/" << denumerator;
    }

    int getNumerator()
    {
        return numerator;
    }

    int getDenumerator()
    {
        return denumerator;
    }

    void setFrac(int num, int denum)
    {
        numerator = num;
        denumerator = denum;
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

    void add(fraction f)
    {
        this->numerator = (numerator * f.denumerator) + (denumerator * f.numerator);
        this->denumerator *= f.denumerator;
    }
};

int main()
{

    for (int i = 0; i < 100; i++)
    {
        fraction f; 
        int a = rand() % 100;
        int b = rand() % 100 + 1;
        f.setFrac(a,b);
        cout << a << '/' << b << " -> " ;
        f.show();
        cout << endl;

    }
    

}