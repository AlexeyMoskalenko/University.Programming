#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int f_i_var = 3;
int s_i_var = 3.14;

double f_d_var = 3;
double s_d_var = 3.14;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << f_i_var << "\t" << s_i_var << endl;
	cout << f_d_var << "\t" << s_d_var << endl;
	system("pause");
    return 0;
}

