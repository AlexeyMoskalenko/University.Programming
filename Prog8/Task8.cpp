#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
int const PREC_SIZE = 10;
void _exit(string msg) {
	std::cout << msg << "\n";
	std::cout << "\n\nДля выхода нажмите любую кнопку... ";
	_getch();
}

void _pause() {
	_getch();
}

void _cls() {
	system("CLS");
}



int main()
{
	char op;
	double lval, rval;
	setlocale(LC_ALL, "Russian");
	std::cout.setf(std::ios::fixed);
	std::cout.precision(PREC_SIZE);
	system("title Добро пожаловать в калькулятор!");
enterVars:
	cout << "Введите выражение для подсчёта:\n";
	cin >> lval >> op >> rval;
	_cls();

	switch (op)
	{
	case '+':
		cout << "Значение выражения: " << lval + rval;
		break;
	case '-':
		cout << "Значение выражения: " << lval - rval;
		break;
	case '*':
		cout << "Значение выражения: " << lval * rval;
		break;
	case '/':
		if (rval == 0) {
			cout << "Деление на 0 запрещено!";
			_pause(); _cls(); goto enterVars;
		}
		cout << "Значение выражения: " << lval / rval;
		break;
	case '.':
		std::cout.precision(lval);
		goto enterVars;
		break;
	default:
		cout << "Неизвестная операция!";
		_pause();
		_cls();
		goto enterVars;
		break;
	}
	_pause();
	_cls();
	goto enterVars;

}