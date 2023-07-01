
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <locale.h>
#include <iostream>
#include <fstream>

using namespace std;


void qsortRec(int* mas, int start, int end) {
	int elem = mas[start];
	int i = start; //Указатель в начало массива
	int j = end; // Указатель в конец массива

	//Центральный элемент массива


	while (start < end) {
		while ((mas[end] >= elem) && (start < end))
			end--;
		if (start != end)
		{
			mas[start] = mas[end];
			start++;
		}
		while ((mas[start] <= elem) && (start < end))
			start++;
		if (start != end)
		{
			mas[end] = mas[start];
			end--;
		}
	}

	mas[start] = elem;
	elem = start;
	start = i;
	end = j;
	//Рекурсивные вызовы, если осталось, что сортировать
	if (start < elem) {
		//"Левый кусок"
		qsortRec(mas, start, elem - 1);
	}
	if (end > elem) {
		//"Правый кусок"
		qsortRec(mas, elem + 1, end);
	}
}

int main() {

	}
