#include <iostream>

using namespace std;

class A
{
protected:
    int a;
public:
    A() {
        a = 0;
    }
    A(int a){
        this-> a = a;
    }
};

class B
{    
public:
    B(int a) {
        A(a);
    }
};

int main() {

    B b = B(100);

return 0;
}