#include <iostream>
#include <conio.h>
#include <cfloat>
#include <cmath>
#include "HumanCode.h"
using namespace std;
namespace HC = HumanCode;


#define NOTNULL 1
int main(){
	setlocale(0, "Russian");
	string menu_list[] = {"Десятичная дробь", "Дробь 1/n"};
	long double						pow_num;
	long double						base;
	long double						equal;

	unsigned long long int			result_l = 1;
	long double						result_d = 1;
	char sign = '\0';
	short method = 0;

	cout << "Для вовзедения числа введите в степень введите значения значения:\n";
	cout << "База: "; cin >> base;
	cout << "Степень: "; cin >> pow_num;
	if (base < 0) { sign = '-';}
	base = abs(base);
	if (pow_num == 0){
		HC::exit("Ответ: 1");
		return 0;
	}
	if (pow_num < 0){
		result_d = exp(abs(pow_num) * log(base));//Узнаем число, которое в теории будет знаменателем. Выражение, где степень abs = знаменателю
		equal = round(result_d);
		HC::_constructor(DBL_DIG - to_string((int)result_d).length());
		if (HC::isequal(equal, result_d)) //Если знаменатель дробный, нет смысла выводить 1/n, поскольку n - дробное число
			method = HC::choose_menu(menu_list, 2, 0, "Выберите способ решения");
		if (method){
			result_l = round(exp(abs(pow_num) * log(base)));
		}
		else
			result_d = exp(pow_num * log(base));
	}
	else{
		result_d = exp(pow_num * log(base));
		equal = round(result_d);
		HC::_constructor(DBL_DIG - to_string((int)result_d).length());
		if (HC::isequal(equal, result_d)){//Проверка на НЕ дробность, как и выше
			method = 1;
			result_l = round(exp(pow_num * log(base)));
		}
	}

	HC::cls();

	if (result_d == INFINITY or result_l == INFINITY) {
		HC::exit("[CRITICAL ERROR] Переполнение буфера переменной! Завершение программы!");
		return 1;
	}

	if (!method) {
		HC::setprecision(result_d);
		cout << "Ответ: " << sign << result_d;
		HC::exit();
		return 0;
	}

	if (pow_num < 0){
		short len = to_string(result_l).length();
		string margin = "         ";
		cout << margin;
		for (int i = 0; i < (len/2); i++) {
			cout << " ";
		}
		cout << "1";
		for (int i = 0; i < (len/2); i++) {
			cout << " ";
		}
		cout << endl;
		cout << "Ответ:";
		if (sign == '-') { margin = " - "; } else { margin = "   "; }
		cout << margin;
		for (int i = 0; i < len; i++) {
			cout << "-";
		}
		cout << endl;
		margin = "         ";
		cout << margin;
		cout << result_l;
	}
	else {
		cout << "Ответ: " << sign << result_l;
	}

	HC::exit();
}