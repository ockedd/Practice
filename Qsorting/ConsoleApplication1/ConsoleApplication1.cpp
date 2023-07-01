
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
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int size;
	int* mas;
	int i;
	cout << "Введите размер массива: ";
	cin >> size;
	cout << "\n";
	int* mas1 = new int[size];
	for (i = 0; i < size; i++) {
		mas1[i] = 1 + rand() % 1001;
		cout << mas1[i] << '\n';
	}
	time_t start = clock(); //время до сортировки
	qsortRec(mas1, 0, size - 1);              //вызов функции сортировки
	time_t stop = clock();             //время после сортировки
	double time = (stop - start) / 1000.0;    //время сортировки

	for (i = 0; i < size; i++) {
		cout << mas1[i] << '\n';
	}
	cout << endl << "Время выполнения сортировки – " << time << " секунд " << endl;
	system("pause");
	return 0;
	}
