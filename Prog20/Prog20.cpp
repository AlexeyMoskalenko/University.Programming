#include <iostream>
#include "HumanCode.h"
#include <vector>

HumanCode HC(true);
using namespace std;


void print_arr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "[" << i << "]" << arr[i] << "\t";
	}
	cout << endl;
}

void sort_array(int arr[], int size){
	bool trigger = true;
	int true_size = size;
	while (trigger){
		trigger = false;
		for (int i = 0; i < size; i++){
			if (arr[i - 1] > arr[i]){
				int temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
				trigger = true;
			}
		}
		size--;
	}
}

int main(){
	unsigned int size;
	cout << "Size: ";
	cin >> size;
	int* ptr = new int[size];
	for (int i = 0; i < size;i++){
		cin >> ptr[i];
	}
	sort_array(ptr, size);
	print_arr(ptr, size);
	delete[] ptr;
}