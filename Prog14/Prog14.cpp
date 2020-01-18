#include <iostream>
using namespace std;

struct diapasone {
	int left_limit;
	int right_limit;
};

diapasone fdia, sdia;

int main()
{
	setlocale(LC_ALL, "RUS");
	int sum;
	cout << "Введите сумму чисел: " << endl;
	cin >> sum;
	cout << "Введите первый диапазон чисел: " << endl;
	cin >> fdia.left_limit >> fdia.right_limit;
	cout << "Введите второй диапазон чисел: " << endl;
	cin >> sdia.left_limit >> sdia.right_limit;
	for (int i = fdia.left_limit; i <= fdia.right_limit; i++)
	{
		for (int k = sdia.left_limit; k <= sdia.right_limit; k++)
		{
			if (i + k == sum)
			{
				cout << "x1 = " << i << endl;
				cout << "x2 = " << k << endl;
				return 0;
			}
		}
	}
	cout << -1;
}
