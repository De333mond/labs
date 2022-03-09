#include <iostream>
#define pi 3.14
using namespace std;

int main()
{
	//1. Даны стороны прямоугольника a и b. Найти его площадь S = a·b и периметр P = 2·(a + b).

	int a, b;

	cout << "#1 Enter a and b: ";
	cin >> a >> b;

	cout << "S = " << a * b << " P = " << 2 * (a + b) << endl;

	//2. Дан диаметр окружности d. Найти ее длину L = π·d. В значения π использовать 3.14.

	int d;

	cout << "#2 Enter d: ";
	cin >> d;
	cout << "L = " << pi * d << endl;

	// 3. Даны два числа a и b. Найти их среднее арифметическое: (a + b)/2

	cout << "#3 Enter a and b: ";
	float da = 5;
	float db = 10;
	cin >> da >> db;
	float res = (da + db)/2; 
	cout << "Average = " << res << endl;

	// 4. Даны два ненулевых числа.Найти сумму, разность, произведение частное их квадратов.

	cout << "#4 Enter a and b: ";
	cin >> a >> b;
	cout << a << " " << b << endl;

	cout << "a*a + b*b = " << a * a + b * b << endl;
	cout << "a*a - b*b = " << a * a - b * b << endl;
	cout << "a*a * b*b = " << (a * a) * (b * b) << endl;
	cout << "a*a / b*b = " << (float)(a * a) / (b * b) << endl;

	//5. Даны два ненулевых числа. Найти сумму, разность, произведение и частное их модулей.

	cout << "#5 Enter a and b: ";
	cin >> a >> b;

	cout << "abs(a) + abs(b) = " << abs(a) + abs(b) << endl;
	cout << "abs(a) - abs(b) = " << abs(a) - abs(b) << endl;
	cout << "abs(a) * abs(b) = " << abs(a) * abs(b) << endl;
	cout << "abs(a) / abs(b) = " << (double)abs(a) / abs(b) << endl;


	return 0;
}
