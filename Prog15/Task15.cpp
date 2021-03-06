#include <iostream>
#include <Windows.h>
#include <string>
#include <climits>
#include "HumanCode.h"

using namespace std;
namespace HC = HumanCode;


int main()
{
	setlocale(LC_ALL, "Russian");
	int new_input;
	int size;
	int temp;
	int arr_int[6];
	int i;
	string input_str;
	cout << "Введите размер массива: ";
	cin >> input_str;
	size = atoi(input_str.c_str());
	
	//zeromemory
	for (int i = 0; i < 6; i++) {
		arr_int[i] = INT_MAX;
	}

	if (size == 0 or size <= 0 or size >= 100000){
		HC::exit("Введено недопустимое значения для размера [1, 100 000]");
		return 0;
	}

	cin >> input_str;

	for(int i = 0; i < size; i++){
		new_input = atoi(input_str.c_str());
		if ((new_input == 0 and input_str != "0") or new_input <= -1000000 or new_input >= 1000000) {
			HC::exit("Введено недопустимое значения [-1 000 000, 1 000 000]");
			i--;
			continue;
		}
		for (int k = 5; k >= 1; k--) {
			if (new_input < arr_int[k]){
				if (arr_int[k] != INT_MAX){
					for (int v = k - 1; v >= 0; v--) {
						temp = arr_int[v];
						arr_int[v] = arr_int[k];
						arr_int[k] = temp;
					}
				}
				arr_int[k] = new_input;
				break;
			}
		}
		HC::cls();
		for (int k = 1; k < 6; k++) { if (arr_int[k] != INT_MAX) { cout << arr_int[k] << "\t"; } }
		cout << endl;
		cin >> input_str;
	}
	HC::pause();
    return 0;
}

