#include <iostream>
#include <string>
#include <conio.h>

void _pause() {
	_getch();
}

void _exit() {
	std::cout << "\n\nДля выхода нажмите любую кнопку...";
	_getch();
}

void _cls() {
	system("CLS");
}


int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Результат вычисления выражения 2+2*2 = " << 2+2*2;
    return 0;
}

