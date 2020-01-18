#include <iostream>
#include "HumanCode.h"
#include <random>
#include <chrono>
#include <thread>

HumanCode HC(true);

using namespace std;

#define VER_EXT

#ifdef VER_EXT
template<typename T>
struct  diapasone{
	T left_limit;
	T right_limit;
};

template<typename T>
bool in_diapasone(diapasone<T> dia, T num, bool strict = true) {
	if (strict)
		if (dia.left_limit <= num and num <= dia.right_limit)	return true; else return false;
	else
		if (dia.left_limit < num and num < dia.right_limit)		return true; else return false;
}
#endif

int main()
{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution_raw(0, 9);
	std::uniform_int_distribution<int> distribution_column(0, 7);
	unsigned short int raw_r = distribution_raw(generator);
	unsigned short int column_r = distribution_column(generator);
	int matrix[10][8];
#ifdef VER_EXT
	diapasone<int> dia1{ 0,9 };
	diapasone<int> dia2{ 0,7 };
#endif

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 8; j++) {
			matrix[i][j] = 0;
		}
	}
	matrix[raw_r][column_r] = 2;

	string title = "TITLE \"" + to_string(raw_r + 1) + "|" + to_string(column_r + 1) + "\"";
	HC.cls();
	//cout << title;

	system(title.c_str());

	for(int k = 0; k < 5; k++){
		HC.cls();
		int raw, column;
		cout << "Попыток осталось: " << 5 - k << endl;
		cout << "Введите строку и столбец: ";
		cin >> raw >> column; raw--; column--;
	#ifndef VER_EXT
		if (raw > 9 or raw < 0 or column > 7 or column < 0) { cout << "Выход за пределы массива"; HC.pause(); k--; continue; }; 	
	#else
		if (!in_diapasone<int>(dia1,raw) or !in_diapasone<int>(dia2, column)){cout << "Выход за пределы массива"; HC.pause(); k--; continue;};
	#endif
		if (matrix[raw][column] == 1) {
			cout << "Эту уже проверяли"; HC.pause(); k--; continue;
		}
		if (matrix[raw][column] == 2) { 
			cout << "Вы угадали!"; HC.exit(); return 1;
		}
		cout << "Промах";
		HC.pause();
		matrix[raw][column] = 1;
	}
	HC.cls();
	cout << "Попытки кончились :(";
	HC.exit();
	return 1;
}