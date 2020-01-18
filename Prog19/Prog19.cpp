#include <iostream>
#include <conio.h>
#include "HumanCode.h"

HumanCode HC(true);

using namespace std;

int main()
{
	unsigned int size = 0;
	unsigned int count[10] {};
	int inp = 0;
//	for (int i = 0; i < 10; i++) count[i] = 0;
	cout << "Введите размер последовательности: ";
	cin >> size;
	cout << endl;
	for (int i = 0; i < size; i++){cin >> inp; count[inp]++;}
	cout << endl;
	for (int i = 0; i < size; i++) if (count[i]) cout << i << ": " << count[i] << endl;
	HC.pause();
}