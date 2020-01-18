#include <iostream>
#include "HumanCode.h"

HumanCode HC(true);

using namespace std;

template<typename T>
struct  diapasone {
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

diapasone<int> upper_case	= { 65, 90 };
diapasone<int> lower_case	= { 97, 122 };
diapasone<int> num_case		= { 48, 57 };

bool is_palindrome(char str[]) {
	unsigned long long int counter = 0;
	unsigned short int size = strlen(str);
	char true_str[21] = "";

	for (size_t i = 0; i <= strlen(str);i++){
		if (!in_diapasone(upper_case, (int)str[i]) and !in_diapasone(lower_case, (int)str[i]) and !in_diapasone(num_case, (int)str[i])) continue;
		true_str[strlen(true_str)] = str[i];
	}

	size = strlen(true_str);

	if (!strlen(true_str)) return false;

	for (int i = 0; i < (int)ceil(size / 2.0); i++){
		int left_ch = (int)true_str[0 + i];
		int right_ch = (int)true_str[size - i - 1];

		if (left_ch != right_ch){
			if ((in_diapasone(upper_case, left_ch) and in_diapasone(lower_case, right_ch) or
				(in_diapasone(lower_case, left_ch) and in_diapasone(upper_case, right_ch)))){
				if (abs(right_ch - left_ch) != 32) return false;
			}
			else return false;
		}
	}

	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[21];
	cin.getline(str, 21, '\n');
	if (is_palindrome(str))
		cout << "Палиндром";
	else
		cout << "Не палиндром";

	HC.exit();
}

