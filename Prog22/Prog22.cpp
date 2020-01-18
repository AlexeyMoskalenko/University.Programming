#include <iostream>
#include "HumanCode.h"

HumanCode HC(true);

using namespace std;

void my_swap(int *f, int* s) {
	int t = *f;
	*f = *s;
	*s = t;
}

int msort(int *f, int *s, int *t){
	if ((*f) > (*s)) my_swap(f, s);
	if ((*s) > (*t)) my_swap(s, t);
	//if ((*f) > (*t)) my_swap(f, t);
	if ((*f) > (*s)) my_swap(f, s);
	return (*t);
}

void v_info(const int* var){
	cout << "Адрес переменной: " << var << "; Значение: " << (*var) << endl;
}

int* add(int *f, const int*s) {
	*f += *s;
	return f;
}

int main()
{
	int f = 5, s = 7, t = 10;
	cout << endl;
	v_info(&f);
	v_info(&s);
	v_info(&t);
	cout << "Максимум: " << msort(&f,&s,&t) << endl;
	v_info(add((add(&f, &s)), &t));
	HC.pause();
}