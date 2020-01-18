#include <iostream>
#include <cstring>
#include <string>
#include "HumanCode.h"

using namespace std;
HumanCode HC(true);

typedef long long int llint;

size_t str_len(const char str[]){
	size_t lenght = 0;
	while (str[lenght] != '\0') lenght++;
	return lenght;
}

int	str_cmp(const char str1[],const char str2[]) {
	size_t size = 0;
	if (str_len(str2) > str_len(str1)) size = str_len(str1); else size = str_len(str2);
	for (int i = 0; i < size; i++){
		if ((int)str1[i] > (int)str2[i]) return 1;
		if ((int)str2[i] > (int)str1[i]) return -1;
	}
	if (str_len(str2) > str_len(str1)) return  -1;
	if (str_len(str1) > str_len(str2)) return	1;
	if (str_len(str2) == str_len(str1)) return	0;
}

char * /*llint*/ str_str(char str[],const char sub[]){
	auto size_str	= str_len(str), size_sub = str_len(sub);
	size_t counter	= size_sub;	counter	= 0;
	llint cpos		= -1;
	size_t i;
	for(i = 0; i < str_len(str); i++){
		if (str[i] != sub[counter]){
			if ((counter > 0) and (counter == size_sub)){	cpos = i - size_sub; break; }
			else											counter = 0;
		}
		else
			counter++;
	}
	if (counter == size_sub) cpos = i - size_sub;
	if (cpos < 0) return nullptr;
	return (&str[0] + cpos);
}

char* str_cat(const char str1[], const char str2[]){
	char* ret = new char[str_len(str1) + str_len(str2)];
	for (int i = 0; i < strlen(str1); i++) ret[i]					= str1[i];
	for (int i = 0; i < strlen(str2); i++) ret[str_len(str1)+i]		= str2[i];
	ret[str_len(str1) + str_len(str2)] = '\0';
	return ret;
}

int main()
{
	char str1[50], str2[50];
	cin.getline(str1, 50);
	cin.getline(str2, 50);
	cout << endl;
	cout << str_len(str1) << "\t" << str_len(str2) << endl;
	unsigned short int cmp = str_cmp(str1,str2);
	if (cmp > 0)	cout << "Строка 1 больше строки 2"	<< endl;
	if (cmp < 0)	cout << "Строка 2 больше строки 1"	<< endl;
	if (cmp == 0)	cout << "Строки равны"				<< endl;
	char* ptr;
	((ptr = str_str(str1, str2)) == nullptr) ? cout << "-1" : cout << (ptr - &str1[0]); cout << endl;
	cout << str_cat(str1, str2)	<< endl;
	HC.pause();
}