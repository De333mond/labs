#include <iostream>

using namespace std;

struct employee
{
    enum etype {a,b,c,d};
    etype type;
};


int main() {

    employee::etype type;
    type = employee::a;



return 0;
}