#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include <list>
#include <iterator>
using namespace std;

bool isNumber(char n)
{
	bool k = false;
	char c[10]{ '0','1','2','3','4','5','6','7','8','9' };
	for (int i = 0; i < 10; i++)
	{
		if (c[i] == n) { k = true; }
	}
	return k;
}
int main()
{
	setlocale(LC_ALL, "RUS");
	int i,k = 0,num;
	double proizv;
	char c[256];
	
	string s,s1;
	list<int> l;
	list<int> ::iterator pos_begin, pos_end;
	fstream f;

	f.open("input.txt", ios::in);
	while (!f.eof())
	{
		f.getline(c, 256);
		s = s + c;
		k++;
	}
	
	cout << s;
	f.close();
	s1 = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (isNumber(s[i])) 
		{
			s1 = s1 + s[i];
		}
		else
		{ 
			if (s1!="")
			{
				istringstream ist(s1);
				ist >> num;
				l.push_back(num);
				s1 = "";
			}
		}
	}
	cout << "\n";
	for (pos_begin = l.begin(); pos_begin != l.end(); ++pos_begin)
		cout << *pos_begin << " ";
	proizv = 1;
	for (pos_begin = l.begin(); pos_begin != l.end(); ++pos_begin)
		proizv *= double(*pos_begin);



	f.open("output.txt", ios::out);
	//вводим количество вещественных чисел
	
	//цикл для ввода вещественных чисел
	//и записи их в файл
	for (pos_begin = l.begin(); pos_begin != l.end(); ++pos_begin)
	{
		
		f << *pos_begin << "\t";
	}
	//закрытие потока
	f.close();
	cout << "\nПроизведение = " << proizv;
	system("pause>>void");
	return 0;
}