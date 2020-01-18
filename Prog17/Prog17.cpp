#include <iostream>
#include "HumanCode.h"
#include <string>

HumanCode HC(true);
using namespace std;

double get_bmi(double weight, double height){
	return (weight / ((height * height)));
}

void printBMI(double bmi) {
	if		(bmi < 18.5)	cout << "Underweight";
	else if (bmi < 25.0)	cout << "Normal weight";
	else if (bmi < 30.0)	cout << "Overweight";
	else					cout << "Obesity";
}

int main()
{
	double weight, height;
	cout << "Введите вес: ";
	cin >> weight;
	cout << "Введите рост: ";
	cin >> height;
	cout << endl;
	printBMI(get_bmi(weight, height / 100));
	HC.pause();
}