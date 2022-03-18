#include <iostream>

using namespace std;

class foo
{
private:
    // (в смысле "объЯвлениЯ")
public:
    foo() // инкрементирование при создании объекта
    {
        count++;
    }
    int getcount() // возвращает значение count
    {
        return count;
    }
};
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
int foo::count = 0; // *определение* count

int main()
{

    asd a;

    cout << "sdf" << endl;

    return 0;
}