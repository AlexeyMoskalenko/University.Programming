#include <iostream>
#include <string>
#include <conio.h>
#include <cfloat>
#include "HumanCode.h"

namespace HumanCode{

	int EQ_ACC = 10;
	const std::string NS = "";

	void _constructor(int eq_acc) {
		EQ_ACC = eq_acc;
	}

	void exit(std::string msg) {
		std::cout << msg << "\n";
		std::cout << "\n\n��� ������ ������� ����� ������... ";
		_getch();
	}

	bool isequal(long double f_var, long double s_var, int eq_acc) {
		long double diff;
		long long int comp_var;
		diff = f_var - s_var;
		for (int i = 0; i != EQ_ACC; i++) {
			diff = diff * 10;
		}
		comp_var = diff;
		if (comp_var == 0)	return true;
		else				return false;
	}

	void pause() {
		_getch();
	}

	void cls() {
		system("CLS");
	}

	void setprecision(long double var) {
		int len, int_var;
		int_var = abs(var);
		len = std::to_string(int_var).length();
		if (!int_var) len -= 1;
		std::cout.setf(std::ios::fixed);
		std::cout.precision(DBL_DIG - len);
		/*std::cout << var << " : " << len << std::endl;*/

	}

	int choose_menu(std::string list[], short int size, int choose_i, std::string header) {
		const short int KEY_UP = 72;
		const short int KEY_DOWN = 80;
		char act;
		while (true) {
			system("CLS");
			if (header != "") {
				std::cout << header << std::endl;
			}
			for (int i = 0; i < size; i++) {
				printf("[%i] ", i + 1);
				std::cout << list[i];
				if (i == choose_i) { printf(" <="); };
				std::cout << std::endl;
			}
			act = _getch();
			if (act == 0 or act == 224) {
				act = _getch();
			}
			switch (act) {
			case KEY_UP:
				if (choose_i > 0) {
					choose_i -= 1;
				}
				break;
			case KEY_DOWN:
				if (choose_i < (size - 1)) {
					choose_i += 1;
				}
				break;
			case 13:
				return choose_i;
				cls();
				break;
			}
		}
	}

	/*void con_alert(char bg_color) {
		system(color);
	}

	void con_normal() {
		system("COLOR 70");
	}

	void con_warning() {

	}*/
	
	/*setprecision(1.0 / 3.0);
	setprecision(-1.0 / 3);
	setprecision((1.0 / 3) + 1);
	setprecision((-1.0 / 3) - 1);*/

}