#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
int const PREC_SIZE = 10;
int const EQ_ACC = 10;
void _exit(string msg){
	std::cout << msg << "\n";
	std::cout << "\n\nДля выхода нажмите любую кнопку... ";
	_getch();
}

bool _isequal(double f_var, double s_var) {
	long double diff;
	long long int comp_var;
	diff = f_var - s_var;
	for (int i = 0; i != EQ_ACC; i++){
		diff = diff * 10;
	}
	comp_var = diff;
	if (comp_var == 0)	return true;
	else				return false;
}

void _pause(){
	_getch();
}

void _cls() {
	system("CLS");
}

int main()
{
	setlocale(LC_ALL, "Russian");


	system("title Калькулятор площади треугольника");
	double len_a, len_b, len_c;
	double Ax1, Ay1, Bx2, By2, Cx3, Cy3, h_p, calc;
	bool trigger = true;
	bool exp_1, exp_2;
	int mode;
	std::cout.setf(std::ios::fixed);
	std::cout.precision(PREC_SIZE);
	_cls();
	cout << "Выберите способ подсчёта площади:\n[1] Через длины сторон\n[2] Через координаты вершин\n\nВыбор: ";
	while (1) {
		cin >> mode;

		if (mode == 1 || mode == 2) {

			break;
		}
		_cls();
		cout << "Неверное значение ввода!\n[1] Через длины сторон\n[2] Через координаты вершин\n\nВыбор: ";
	}
	_cls();
	if (mode == 1) {
		cout << "Введите значения сторон:\n";
		cout << "[A]:"; cin >> len_a;
		cout << "[B]:"; cin >> len_b;
		cout << "[C]:"; cin >> len_c;
		_cls();
		exp_1 = (len_a > len_b + len_c) or (len_b > len_c + len_a) or (len_c > len_a + len_b);
		exp_2 = (len_a <= 0) or (len_b <= 0) or (len_c <= 0);
		if (exp_1 or exp_2) { _exit("[Ошибка] Такой треугольник не может существовать"); return 1;}
		h_p = ((len_a + len_b + len_c) / 2.0);
		cout << "Результат вычисления:\nПлощадь треугольника(S) = " << sqrtl(h_p * (h_p - len_a) * (h_p - len_b) * (h_p - len_c));
	}
	else{
		cout << "Введите через пробел координаты вершин:\n";
		cout << "A(x,y): "; cin >> Ax1 >> Ay1;
		cout << "B(x,y): "; cin >> Bx2 >> By2;
		cout << "C(x,y): "; cin >> Cx3 >> Cy3;
		_cls();
		calc = ((Bx2 - Ax1) * (Cy3 - Ay1)) - ((Cx3 - Ax1) * (By2 - Ay1));
		if (_isequal(calc,0)) { _exit("[Ошибка] Такой треугольник не может существовать"); return 1;}
		cout << "Результат вычисления:\nПлощадь треугольника(S) = " << 0.5 * abs(calc);
	}
	
	_exit("");
}
