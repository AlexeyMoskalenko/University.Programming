#include <iostream>
#include "HumanCode.h"
#include <string>
#include <climits>

using namespace std;
namespace HC = HumanCode;

//unsigned long long int factorial(unsigned long long int num) {
//	if (num == 0 or num == 1) return 1;
//	return num * factorial(num - 1);
//}


int main()
{
	setlocale(LC_ALL, "Russian");
	string inp_str;
	unsigned long long int fact, last_fact = 1;
	fact = 1;
	last_fact = 1;
	short inp_int = 1;
	cout << "Введите значение для подсчёта" << endl;
	cin >> inp_str;
	if (inp_str == "limit") {
		cout << ULLONG_MAX;
		HC::pause();
		HC::cls();
		cout << "Введите значение для подсчёта" << endl;
		cin >> inp_str;
	}

	inp_int = atoi(inp_str.c_str());
	if (inp_int == 0 and inp_str != "0" or inp_int < 0) {
		HC::exit("Вводимое значение недопустимо для обработки");
		return 0;
	}
	if (inp_int == 0 or inp_int == 1) {
		HC::exit("Значение факториала: 1");
		return 0;
	}

	HC::cls();
	for (int i = 1; i < inp_int + 1; i++) {
		if (to_string(ULLONG_MAX).length() - 1 <= to_string(fact).length()){
			printf("Ошибка: Максимальное значение вычисленного[%i]факториала:", i - 2); cout << last_fact;
			HC::pause();
			return 0;
		}
		last_fact = fact;
		fact = fact * i;
		//cout << "i: " << i << "\tfact:" << fact << "\tlength ULLONG_MAX: " << to_string(ULLONG_MAX).length() << "\tlength str: " << to_string(fact).length() << endl;
	}
	if (fact == 0) {
		HC::cls();
		HC::exit("Ошибка: Переполнение буфера!");
		return 0;
	}
	cout << "Значение факториала: " << fact;
	cout << endl;

	HC::exit();
    return 0;
}

