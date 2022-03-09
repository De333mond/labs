#include <iostream>
#include <cmath>
using namespace std;

// преобразованная функция
inline float ff(float x)
{
    return -log10(x) + 0.5;
}

inline float f(float x)
{
    return x + log10(x) - 0.5;
}

// 1 производная
inline float g(float x)
{
    return 1 + 1 / (x * log(10));
}
// 2 производная
inline float h(float x)
{
    return -1 / x * x * log(10);
}

int main()
{
    float a = 0.5;
    float b = 1.5;
    float x = (a + b) / 2;
    float prescision = 0.0001;
    int steps = 0;

    // Метод простых итераций
    while (abs(x - ff(x)) > prescision)
    {
        x = ff(x);
        steps++;
    }
    cout << "Answer: " << x << " +-" << prescision << " take: " << steps << " steps " << endl;

    //Метод касательных

    steps = 0;
    if (ff(x) * h(x) < 0) // выбор стороны начала
        a = b;
    x = a;
  
    do
    {
        // находим точку пересечения касательной и оси Ох
        x = x - f(x) / g(x);
        // находим новое значение а
        steps = steps + 1;
    } while (f(x - prescision) * f(x + prescision) > 0);

    cout << "Answer: " << x << " +-" << prescision << " take: " << steps << " steps " << endl;
    return 0;
}