#include <iostream>
#include <conio.h>
#include <string>
#include <random>
#include "HumanCode.h"

using namespace std;
namespace HC = HumanCode;

int main()
{
	setlocale(0, "Russian");
	const int MAX_TRY = 5;
	const int MAX_NUM = 100;

	std::random_device rand_dev;
	std::mt19937 engine(rand_dev());
	std::uniform_int_distribution<> dist(0, MAX_NUM);
	//////////////////////////////////////////////////

	int user_num;
	int rand_num;
	printf("Поиграем? Угадай число в диапазоне[0,%i]!", MAX_NUM);
	HC::pause();
StartGame:
	HC::cls();
	rand_num = dist(engine);
	printf("Поехали.У тебя %i попыток. И я уже загадал число! Твой вариант:", MAX_TRY);
	for (int i = 1; i != MAX_TRY + 1; i++) {
		cin >> user_num;
		HC::cls();
		if (user_num == rand_num) { printf("Поздравляю, ты угадал!\n"); goto NotLooserMark; }
		if (user_num > rand_num) {
			printf("Промах !\tТвоё число больше!\t\tПопыток осталось:%i\n", MAX_TRY - i);
		}
		else {
			printf("Промах !\tТвоё число меньше!\t\tПопыток осталось:%i\n", MAX_TRY - i);
		}
		printf("Твой вариант:");
	}
	HC::cls();
	printf("Ты проиграл :(\n");
NotLooserMark:
	printf("Сыграем еще раз?(1 - да)\nВыбор:");
	if (_getch() == '1') { goto StartGame; }
	else { HC::exit("\nДо новых встреч!"); }
}