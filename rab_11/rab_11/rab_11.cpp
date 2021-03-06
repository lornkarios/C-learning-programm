// rab_11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

struct Date
{
	int day,
		month,
		year;
};

void sravn(char a1[100],char a2[100])
{
	for (int i = 0; i < 100; i++)
	{
		a1[i] = a2[i];
	}
}


class Tovar // имя класса
{
private: // спецификатор доступа private
	char name[100];
	Date date;
	float cost;


public: // спецификатор доступа public
	Tovar()
	{
		
		strcpy_s(name,"");
		date.day = 1;
		date.month = 1;
		date.year = 1996;
		cost = 0;
	}
	Tovar(char name1[100],int day,int month,int year,float cost1)
	{
		strcpy_s(name,name1);
		Date date1;
		date1.day = day;
		date1.month = month;
		date1.year = year;
		date = date1;
		cost = cost1;

	}
	friend void vivod(Tovar&);
	friend std::ostream & operator<< (std::ostream &out, const Tovar &tovar);
	friend std::istream& operator>> (std::istream &in,	Tovar &tovar);
};



std::ostream& operator<< (std::ostream &out, const Tovar &tovar)
{
	// поскольку operator<< является другом класса Tovar, то мы имеем прямой доступ к членам Tovar
	out << "Tovar(" << tovar.name << ", " << tovar.date.day<<"."<< tovar.date.month<<"."<<tovar.date.year<<" , " << tovar.cost << "$ )";

	return out;
}
std::istream& operator>> (std::istream &in, Tovar &tovar)
{
	// поскольку operator>> является другом класса Point, то мы имеем прямой доступ к членам Point
	// обратите внимание, параметр point (объект класса Point) должен быть не константным, чтобы мы имели возможность изменить члены класса
	int day, month, year;
	Date date1;
	in >> tovar.name;
	in >> day;
	in >> month;
	in >> year;
	date1.day = day;
	date1.month = month;
	date1.year = year;
	tovar.date = date1;
	in >> tovar.cost;

	return in;
}

void vivod(Tovar& tovar)
{
	if (((tovar.date.month == 1) || (tovar.date.month == 2) || (tovar.date.month == 3)) && (tovar.cost >= 100) && (tovar.cost <= 500))
	{
		cout << tovar;
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	char name[100];
	strcpy_s(name, "Йогурт");
	Tovar tovar1(name,3,1,1996,150);
	strcpy_s(name, "Кефир");
	Tovar tovar2(name, 2, 3, 1998, 4);
	strcpy_s(name, "Творог");
	Tovar tovar3(name, 5, 4, 2000, 101);
	strcpy_s(name, "Простокваша");
	Tovar tovar4(name, 1, 5, 2013, 499);
	Tovar tovar5;

	cin >> tovar5;
	vivod(tovar1);
	vivod(tovar2);
	vivod(tovar3);
	vivod(tovar4);
	vivod(tovar5);
	//cout << tovar1;
	cout << "2";
	system("pause");
    return 0;
}

