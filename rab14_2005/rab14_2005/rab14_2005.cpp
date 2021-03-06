// rab14_2005.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"



struct node {
	node* next;
	char FIO[200];
	double stipend;
	char mestZhit[100];
};

class slist {
private:
	node * lst;
	size_t cnt;
public:
	slist(void);
	~slist();

	bool add(string FIO, int val, string mesto);

	void clear(void);

	void bsort(void);


	size_t size(void)  const { return cnt; }
	bool   empty(void) const { return (lst == NULL); }
	node*  begin(void) const { return lst; }
	node*  begin(void) { return lst; }
};
void slist_print(std::ostream& _out, const slist& lst);
slist::slist(void) :lst(NULL), cnt(0) {}
slist::~slist() {
	clear();
}

void slist::bsort(void) {
	node* t, *m, *a, *b;
	if (lst == NULL)
		return;

	for (bool go = true; go; ) {
		go = false;
		a = t = lst;
		b = lst->next;

		while (b != NULL) {
			if (a->stipend > b->stipend) {
				if (t == a)
					lst = b;
				else
					t->next = b;

				a->next = b->next;
				b->next = a;

				m = a, a = b, b = m;
				go = true;
			}
			t = a;
			a = a->next;
			b = b->next;
		}
	}
}
//добавление
bool slist::add(string FIO,int val,string mesto) {
	node* p = new (std::nothrow) node();
	if (p != NULL) {
		strcpy_s(p->FIO, FIO.c_str());
		p->stipend = val;
		strcpy_s(p->mestZhit, mesto.c_str());
		p->next = lst;
		lst = p;
		++cnt;
	}
	return (p != NULL);
}



//удаление всех
void slist::clear(void) {
	node* t;
	while (lst != NULL) {
		t = lst;
		lst = lst->next;
		delete t;
	}
	cnt = 0;
}

//печать
void slist_print(std::ostream& _out, const slist& lst) {
	for (const node* p = lst.begin(); p != NULL; p = p->next)
		_out << p->FIO << ' ' << p->stipend << ' ' << p->mestZhit << " |     ";
	_out << std::endl;
}

int main()
{
	setlocale(LC_ALL, "rus");

	
	slist s;
	s.add("Kovalev A V", 1200, "Samara");
	s.add("Sidorov E V", 1400, "Sizran");
	s.add("Egorov V A", 1500, "Krim");
	s.add("Vilyaev R S", 1600, "Saratov");
	s.add("Petrov  V Z", 1800, "Moskva");
	s.add("Emtsev B V", 1100, "Krasnodar");
	s.add("Lyah E L", 1000, "Krasnodar");
	s.add("Konovalov K K", 1900, "Kurgan");

	
	slist_print(cout, s);
	cout << "\n";
	cout << "\n";
	cout << "\n";
	s.bsort();
	slist_print(cout,s);
	cout << "\n";
	system("pause");

    return 0;
}

