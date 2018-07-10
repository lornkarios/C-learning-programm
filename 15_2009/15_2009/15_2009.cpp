// 15_2009.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
void Podp(double *a, int N)
{
	for (int i = 0; i < N; i++) {
		// Заполнение массива и вывод значений его элементов
		a[i] = 1/((double)(i+1));
		cout << "Value of " << i+1 << " element is " << a[i] << endl;
	}
}

int main()
{
	int N;
	setlocale(LC_ALL, "russian");
	cout << "Введите N количество элементов массива  ";
	cin >> N;
	double *mas = new double[N]; // Выделение памяти для массива
	Podp(mas, N);
	delete [] mas;
	system("pause");
    return 0;
}

