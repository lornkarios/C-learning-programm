// rab8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
	int main()
	{
		int n = 13;
		int mas[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
		list <int> s;
		for (int i = 0; i < n; i++)
		{
			if (((i + 1) % 2 == 0) && (!(std::find(s.begin(), s.end(), i + 1) != s.end()))) 
			{
				int b = mas[i];
				mas[i] = mas[i - 1];
				mas[i - 1] = b;
				s.push_back(i + 1);
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << mas[i]<<"  ";
		}
		system("pause");
		return 0;
	}

