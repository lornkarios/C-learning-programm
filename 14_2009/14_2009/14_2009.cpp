// 14_2009.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
double func(double x)
{
	return 2 * x*x - x * x*x*x - 1 - log(x);
}

int main()
{
	setlocale(LC_ALL, "russian");
	double a, b,h;
	cout << "Введите границы: ";
	cin >> a >> b;
	cout << "Введите шаг: ";
	cin >> h;
	cout << "x        f(x)\n";
	for (int i = 0; i < (b-a) / h; i++)
	{
		cout << a + h * i <<"        "<< func(a + h * i)<<"\n";
	}
	cout << "\n";
	system("pause");
    return 0;
}

