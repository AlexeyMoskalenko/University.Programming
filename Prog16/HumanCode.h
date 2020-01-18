#pragma once
#include <iostream>
#include <string>
#include <conio.h>

namespace HumanCode {
	extern int EQ_ACC;
	extern const std::string NS;
	int choose_menu(std::string list[], short int size, int choose_i = 1, std::string header = "");
	bool isequal(double f_var, double s_var);
	void setprecision(double var);
	void exit(std::string msg = "");
	void pause();
	void cls();
}