#include "stdafx.h"
#include "clocale"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	system("COLOR 02");
	int			first;
	int			second;
	int			temp;
	cout << "Введите значение переменных: " << endl;
	cin >> first >> second;
	temp	= second;
	second	= first;
	first	= second;
	cout << "Первая переменная: " << first << endl << "Вторая переменная: " << second << endl;
	system("pause");
	return 0;
}

//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	system("COLOR 02");
//	int			first;
//	int			second;
//	cout << "Введите значение переменных: " << endl;
//	cin >> first >> second;
//	swap(first, second);
//	cout << endl;
//	cout << "Первая переменная: " << first << endl << "Вторая переменная: " << second <<endl;
//	system("pause");
//	return 0;
//}