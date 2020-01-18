#include <iostream>
#include <random>
#include "HumanCode.h"

HumanCode HC(true);

using namespace std;

int main()
{
	unsigned short const int SIZE = 20;
	int int_array[SIZE];
	int MAX, MIN;
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> distribution(-100, 100);
	for (int i = 0; i < SIZE; i++){
		int_array[i] = distribution(generator);
		cout << int_array[i] << " ";
	}
	MAX = int_array[0];
	MIN = int_array[0];
	for (int i = 0; i < SIZE; i++) {
		if (int_array[i] < MIN) MIN = int_array[i];
		if (int_array[i] > MAX) MAX = int_array[i];
	}
	cout << endl << MIN << endl << MAX;
	HC.pause();
}