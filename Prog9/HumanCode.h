#pragma once
//#include <iostream>
#include <string>
#include <conio.h>

namespace HumanCode {
	extern int EQ_ACC;
	extern const std::string NS;
	void _constructor(int eq_acc);
	bool isequal(long double f_var, long double s_var, int eq_acc = EQ_ACC);
	void setprecision(long double var);
	int choose_menu(std::string list[], short int size, int choose_i = 0, std::string header = "");
	void exit(std::string msg = "");
	void pause();
	void cls();
}