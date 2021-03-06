#include <iostream>
#include <string>
#include "HumanCode.h"

using namespace std;

namespace HC = HumanCode;

string factorization(long long int N) {
	string result;
	int k = 1;
	for (int i = 2; i <= N; i++){
		if (N % i == 0){
			k = 1;
			N /= i;
			while(N % i == 0){
				k++;
				N /=i;
			}
			if (k != 1) result += to_string(i) + "^" + to_string(k) + "*";
			else result += to_string(i) + "*";
		}
	}
	result[result.length() - 1] = '\0';
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	long long int num;
	string result;
	int k = 1;
	cout << "Введите N для факторизации: ";
	cin >> num;

	result = factorization(num);

	cout << result;
	HC::exit();
    return 0;
}