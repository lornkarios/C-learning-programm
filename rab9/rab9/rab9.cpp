
#include "stdafx.h"
#include <list>

using namespace std;

struct Shop {

	float volOfSal;       //объём продаж
	char City[100];		//город  
};

bool sravn(char a1[100], char a2[100])
{
	
	bool b = true;
	for(int i=0;i<100;i++)
	{
		
		if (a1[i] != a2[i])
		{
			b = false; break;
		}

	}
	return b;
}

int main()
{
	const char *FName = "file.bin"; //Путь к файлу. Вписывайте свой.
	Shop magaz;     //teacher - Записываемый в файл объект структуры
	Shop *w1=new Shop;          //w1 - читаемый из файл объект структуры
	int n,i,index; 
	ofstream f1;
	ifstream f2;
	FILE *f;
	double sum;
	char CityName[100];
	list<Shop> a;
	bool z_exit = true;
	setlocale(LC_ALL, "Russian");
	
	while (z_exit==true) {
		system("cls");
		cout << "Введите 1 если хотите добавить магазин.\nВведите 2 если хотите вывести весь список.\nВведите 3 средний объем продаж.\nВведите 4 макс объем продаж по городу.\nВведите 5 чтобы перезаписать файл.\nВведите 6 чтобы выйти.\n";
		cin >> n;
		
		switch (n) 
		{
			case 1:
				cout << "\n\nВведите объём продаж = ";
				cin >> magaz.volOfSal;
				cout << "\n\nВведите город :";
				cin >> magaz.City;
				/*Записываем структуру в файл*/

			
				i = 0;
				f2 = ifstream(FName, ios::binary | ios::in);
				if (f2.is_open()) {


					//f2.read((char*)&w1, sizeof(magaz));
					Shop *x = new Shop; //считывание из бинарного файла записей 
					while (f2.read((char*)(x), sizeof(Shop)))
					{

						//добавление записи в вектор
						a.push_back(*x);
						//cout << "\n" << i << "  " <<w1.volOfSal << "  " << w1.City;
						i++;
					}


				}
				f2.close();
				a.push_back(magaz); i++;

				f1 = ofstream(FName, ios::binary | ios::out);
				if (f1)
				{
					for (int j = 0; j < i; j++) { //запись в бинарный файл структуры
						f1.write((char*)(&a.back()), sizeof(Shop));
						a.pop_back();
					}
				}
				else cerr << "File not found";
				f1.close();
				
				
				
				break;
			case 2:

				
				i = 0;
				f2 = ifstream(FName, ios::binary | ios::in);
				if (f2.is_open()) {
					

					//f2.read((char*)&w1, sizeof(magaz));
					Shop *x = new Shop; //считывание из бинарного файла записей 
					while (f2.read((char*)(x), sizeof(Shop)))
					{
						
						//добавление записи в вектор
						a.push_back(*x);
						//cout << "\n" << i << "  " <<w1.volOfSal << "  " << w1.City;
						i++;
					}
					
					
				}
				f2.close();
				for (int j = 0; j < i; j++)
				{
					
					  Shop v =a.back();
					  cout << "\n" << j+1 << "  " << v.volOfSal << "  " << v.City;
					  a.pop_back();
				}
				cout << "\n"; 
				system("pause");
				
				break;
			case 3:
				i = 0;
				f2 = ifstream(FName, ios::binary | ios::in);
				if (f2.is_open()) {


					//f2.read((char*)&w1, sizeof(magaz));
					Shop *x = new Shop; //считывание из бинарного файла записей 
					while (f2.read((char*)(x), sizeof(Shop)))
					{

						//добавление записи в вектор
						a.push_back(*x);
						//cout << "\n" << i << "  " <<w1.volOfSal << "  " << w1.City;
						i++;
					}


				}
				f2.close();
				sum = 0;
				for (int j = 0; j < i; j++)
				{
					sum += a.back().volOfSal;
					a.pop_back();
				}
				cout << "\nСреднее значение объёма продаж по всем магазинам = " << (sum / i)<<"\n";
				system("pause");
				break;
			case 4:

				cout << "\nНапишите название города: ";
				cin >> CityName;
				i = 0;
				f2 = ifstream(FName, ios::binary | ios::in);
				if (f2.is_open()) {


					//f2.read((char*)&w1, sizeof(magaz));
					Shop *x = new Shop; //считывание из бинарного файла записей 
					while (f2.read((char*)(x), sizeof(Shop)))
					{

						//добавление записи в вектор
						a.push_back(*x);
						//cout << "\n" << i << "  " <<w1.volOfSal << "  " << w1.City;
						i++;
					}


				}
				f2.close();
				sum = -1; 
		//		sizeof(a.back().City);
				
				for (int j = 0; j < i; j++)
				{

					if((sravn(CityName,a.back().City))&& (a.back().volOfSal > sum))
					{
						index = j;
						sum = a.back().volOfSal;
					}
					a.pop_back();
				}
				cout << "\nМаксимальный средний объём продаж в магазине под номером = "<<index+1<<"\n";
				system("pause");
				break;
			case 5:
				f1 = ofstream(FName, ios::binary | ios::out);
				f1.close();
				break;
			case 6:
				z_exit = false;
				break;

		}






	}
	
	
	return 0;
}