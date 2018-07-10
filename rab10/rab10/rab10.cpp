
#include "stdafx.h"


using namespace std;
struct FIO
{
	char Fam[100];
	char Name[100];
	char Otch[100];
};
struct Sotrudik 
{

	FIO FIO1;
	int tabNomer;       //объём продаж
	char dolzhnost[100];		//город 
	int otdel;
};
struct Rabota
{
	int tabNomer;
	float zarplata;
	char mesyaz[100];
};
bool sravn(char a1[100], char a2[100])
{

	bool b = true;
	for (int i = 0; i<100; i++)
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
	const char *FName = "sotrud.bin"; //Путь к файлу. Вписывайте свой.
	const char *FName2 = "rabota.bin";
	Sotrudik magaz;     //teacher - Записываемый в файл объект структуры
	Rabota magaz1;
	Sotrudik *w1 = new Sotrudik;          //w1 - читаемый из файл объект структуры
	int n, i,i2,i3, index;
	ofstream f1;
	ifstream f2;
	FILE *f;
	double sum;
	char CityName[100];
	list<Sotrudik> a;
	list<float> zp;
	list<Rabota> a1;
	Rabota a2[100];
	Rabota a3[100];
	float min = 9999999999; int num;
	bool z_exit = true;
	setlocale(LC_ALL, "Russian");

	while (z_exit == true) {
		system("cls");
		cout << "Введите 1 если хотите добавить сотрудника в 1 файл.\nВведите 2 если хотите добавить зарплату во 2 файл.\nВведите 3 если хотите вывести весь список 1 файла.\nВведите 4 если хотите вывести весь список 2 файла.\nВведите 5 чтобы вывести информацию о сотрудниках отдела.\nВведите 6 чтобы вывести сотрудника с минимальной зарплатой.\nВведите 7 чтобы перезаписать 1 файл\nВведите 8 чтобы перезаписать 2 файл.\nВведите 9 чтобы выйти.\n";
		cin >> n;

		switch (n)
		{
		case 1:
			cout << "\n\nВведите ФИО = ";
			cin >> magaz.FIO1.Fam>>magaz.FIO1.Name>>magaz.FIO1.Otch;
			cout << "\n\nВведите табельный номер = ";
			cin >> magaz.tabNomer;
			cout << "\n\nВведите номер отдела = ";
			cin >> magaz.otdel;
			cout << "\n\nВведите должность: ";
			cin >> magaz.dolzhnost;
			/*Записываем структуру в файл*/


			i = 0;
			f2 = ifstream(FName, ios::binary | ios::in);
			if (f2.is_open()) {


				//f2.read((char*)&w1, sizeof(magaz));
				Sotrudik *x = new Sotrudik; //считывание из бинарного файла записей 
				while (f2.read((char*)(x), sizeof(Sotrudik)))
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
					f1.write((char*)(&a.back()), sizeof(Sotrudik));
					a.pop_back();
				}
			}
			else cerr << "File not found";
			f1.close();



			break;
		case 2:
			
			cout << "\n\nВведите табельный номер = ";
			cin >> magaz1.tabNomer;
			cout << "\n\nВведите зарплату: ";
			cin >> magaz1.zarplata;
			cout << "\n\nВведите месяц: ";
			cin >> magaz1.mesyaz;
			/*Записываем структуру в файл*/


			i = 0;
			f2 = ifstream(FName2, ios::binary | ios::in);
			if (f2.is_open()) {


				//f2.read((char*)&w1, sizeof(magaz));
				Rabota *x = new Rabota; //считывание из бинарного файла записей 
				while (f2.read((char*)(x), sizeof(Rabota)))
				{

					//добавление записи в вектор
					a1.push_back(*x);
					//cout << "\n" << i << "  " <<w1.volOfSal << "  " << w1.City;
					i++;
				}


			}
			f2.close();
			a1.push_back(magaz1); i++;

			f1 = ofstream(FName2, ios::binary | ios::out);
			if (f1)
			{
				for (int j = 0; j < i; j++) { //запись в бинарный файл структуры
					f1.write((char*)(&a1.back()), sizeof(Rabota));
					a1.pop_back();
				}
			}
			else cerr << "File not found";
			f1.close();



			break;
		case 3:


			i = 0;
			f2 = ifstream(FName, ios::binary | ios::in);
			if (f2.is_open()) {


				//f2.read((char*)&w1, sizeof(magaz));
				Sotrudik *x = new Sotrudik; //считывание из бинарного файла записей 
				while (f2.read((char*)(x), sizeof(Sotrudik)))
				{

					//добавление записи в вектор
					a.push_back(*x);
					//cout << "\n" << i << "  " <<w1.volOfSal << "  " << w1.City;
					i++;
				}


			}
			f2.close();
			cout << "\nтабельный №                   FIO                отдел              должность";
			for (int j = 0; j < i; j++)
			{

				Sotrudik v = a.back();
				cout << "\n" << v.tabNomer << "                   " << v.FIO1.Fam<<" "<<v.FIO1.Name<<" "<<v.FIO1.Otch << "       " << v.otdel<<"              "<<v.dolzhnost;
				a.pop_back();
			}
			cout << "\n";
			system("pause");

			break;
		case 4:
			i = 0;
			f2 = ifstream(FName2, ios::binary | ios::in);
			if (f2.is_open()) {


				//f2.read((char*)&w1, sizeof(magaz));
				Rabota *x = new Rabota; //считывание из бинарного файла записей 
				while (f2.read((char*)(x), sizeof(Rabota)))
				{

					//добавление записи в вектор
					a1.push_back(*x);
					//cout << "\n" << i << "  " <<w1.volOfSal << "  " << w1.City;
					i++;
				}


			}
			f2.close();
			cout << "\nтабельный №                   зарплата            месяц";
			for (int j = 0; j < i; j++)
			{

				Rabota v = a1.back();
				cout << "\n" << v.tabNomer << "                              " << v.zarplata<<"            "<<v.mesyaz;
				a1.pop_back();
			}
			cout << "\n";
			system("pause");

			break;
		case 5:
			cout << "\nВведите номер отдела: ";
			cin >> n;
			i = 0;
			f2 = ifstream(FName, ios::binary | ios::in);
			if (f2.is_open()) {


				//f2.read((char*)&w1, sizeof(magaz));
				Sotrudik *x = new Sotrudik; //считывание из бинарного файла записей 
				while (f2.read((char*)(x), sizeof(Sotrudik)))
				{

					//добавление записи в вектор
					a.push_back(*x);
					//cout << "\n" << i << "  " <<w1.volOfSal << "  " << w1.City;
					i++;
				}


			}
			f2.close();
			i2 = 0;
			f2 = ifstream(FName2, ios::binary | ios::in);
			if (f2.is_open()) {


				//f2.read((char*)&w1, sizeof(magaz));
				Rabota *x = new Rabota; //считывание из бинарного файла записей 
				while (f2.read((char*)(x), sizeof(Rabota)))
				{

					//добавление записи в вектор
					a2[i2]=(*x);
					//cout << "\n" << i << "  " <<w1.volOfSal << "  " << w1.City;
					i2++;
				}


			}
			f2.close();

			
			

			cout << "\nтабельный №                   FIO                отдел              должность            зарплата";
			for (int j = 0; j < i; j++)
			{

				Sotrudik v = a.back();
				if (v.otdel == n) {
					
					sum = 0;
					for (int j=0;j<i2;j++)
					{
						if (a2[j].tabNomer == v.tabNomer)
						{
							sum += a2[j].zarplata;
						}
						
					}

					cout << "\n" << v.tabNomer << "                   " << v.FIO1.Fam << " " << v.FIO1.Name << " " << v.FIO1.Otch << "       " << v.otdel << "              " << v.dolzhnost << "            " << sum;
				}
				a.pop_back();
			}
			cout << "\n";
			
			system("pause");

			
			break;

		case 6:
			i = 0;
			f2 = ifstream(FName, ios::binary | ios::in);
			if (f2.is_open()) {


				//f2.read((char*)&w1, sizeof(magaz));
				Sotrudik *x = new Sotrudik; //считывание из бинарного файла записей 
				while (f2.read((char*)(x), sizeof(Sotrudik)))
				{

					//добавление записи в вектор
					a.push_back(*x);
					//cout << "\n" << i << "  " <<w1.volOfSal << "  " << w1.City;
					i++;
				}


			}
			f2.close();
			i2 = 0;
			f2 = ifstream(FName2, ios::binary | ios::in);
			if (f2.is_open()) {


				//f2.read((char*)&w1, sizeof(magaz));
				Rabota *x = new Rabota; //считывание из бинарного файла записей 
				while (f2.read((char*)(x), sizeof(Rabota)))
				{

					//добавление записи в вектор
					a2[i2] = (*x);
					//cout << "\n" << i << "  " <<w1.volOfSal << "  " << w1.City;
					i2++;
				}


			}
			f2.close();

			
			i3 = 0;
			for (int j = 0; j < i2; j++)
			{
				bool t = true; int l;
				for (int j1 = 0; j1 < i3; j1++)
				{
					if (a3[j1].tabNomer == a2[j].tabNomer)
					{
						t = false; l = j1;
					}
				}
				if (t)
				{
					a3[i3] = a2[j];
					i3++;
				}
				else
				{
					a3[l].zarplata += a2[j].zarplata;
				}
			}
			
			for (int j = 0; j < i3; j++)
			{
				if (min > a3[j].zarplata)
				{
					min = a3[j].zarplata;
					num = a3[j].tabNomer;
				}
			}
			for (int j = 0; j < i; j++)
			{
				if (a.back().tabNomer == num)
				{
					Sotrudik v = a.back();
					cout << "\nCотрудник с минимальной зарплатой - " << v.tabNomer << "   " << v.FIO1.Fam << " " << v.FIO1.Name << " " << v.FIO1.Otch << "       " << v.otdel << "  " << v.dolzhnost << "  " << min<<"\n";
					system("pause");
				}
				a.pop_back();
			}
			break;
		case 7:
			f1 = ofstream(FName, ios::binary | ios::out);
			f1.close();
			break;
		case 8:
			f1 = ofstream(FName2, ios::binary | ios::out);
			f1.close();
			break;
			break;
		case 9:
			z_exit = false;
			break;

		}






	}


	return 0;
}