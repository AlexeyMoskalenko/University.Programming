#include "stdafx.h"
#include "clocale"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	system("COLOR 02");
	int	first, second;
	cout << "Введите значение переменных: "<< endl;
	cin >> first >> second;
	cout	<< "Результаты вычислений:" << endl
			<< first + second << endl 
			<< first - second << endl
			<< first * second << endl 
			<< first / second << endl;
	system("pause");
	return 0;
}

//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	system("COLOR 02");
//	double	first, second;
//	cout << "Введите значение переменных: " << endl;
//	cin >> first >> second;
//	cout << "Результаты вычислений:" << endl
//		<< first + second << endl
//		<< first - second << endl
//		<< first * second << endl
//		<< first / second << endl;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	system("COLOR 02");
//	int		first;
//	double	second;
//	cout << "Введите значение переменных: " << endl;
//	cin >> first >> second;
//	cout << "Результаты вычислений:" << endl
//		<< first + second << endl
//		<< first - second << endl
//		<< first * second << endl
//		<< first / second << endl;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	system("COLOR 02");
//	double		first;
//	int			second;
//	cout << "Введите значение переменных: " << endl;
//	cin >> first >> second;
//	cout << "Результаты вычислений:" << endl
//		<< first + second << endl
//		<< first - second << endl
//		<< first * second << endl
//		<< first / second << endl;
//	system("pause");
//	return 0;
//}