#include "HumanCode.h"

using namespace std;
HumanCode HC(true);
int main()
{

	int inp_num = 0;
	int power = 0;
	int i = 1;
	cout << "Введите число: ";
	cin >> inp_num;
	for (i = 1; i <= inp_num;){
		power++;
		i*= 2;
	}
	cout << "Степень двойки: " << power;
	HC.exit();
}

