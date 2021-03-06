#include <iostream>
#include <string>
#include "HumanCode.h"
using namespace std;
namespace HC = HumanCode;

int main() {
	setlocale(LC_ALL, "Russian");
	string	str = "";
	int		number;
	cout << "Введите число для проверки: ";
	cin >> str;
	number = atoi(str.c_str());
	if (!number) {
		HC::exit("Определение невозможно для введенного значения");
		return 0;
	}
	for (int i = 2; i < number; i++) {
		if (number % i == 0) {
			str = "Число [" + str + "] составное";
			HC::exit(str);
			return 0;
		}
	}
	str = "Число [" + str + "] простое";
	HC::exit(str);
	return 0;
}