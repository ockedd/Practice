
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <locale.h>
#include <iostream>
#include <fstream>

using namespace std;


void qsortRec(int* mas, int start, int end) {
	int elem = mas[start]; //опорный элемент
	int i = start; //начало массива
	int j = end; //конец массива

	while (start < end) { //пока границы не сомкнутся
		while ((mas[end] >= elem) && (start < end)) //пока конечный элемент массива больше опорного
			end--; //сдвигаем правую границу влево
		if (start != end) //границы не сомкнулись
		{
			mas[start] = mas[end]; //перемещаем элемент [start] на место разрешающего
			start++;//сдвигаем левую границу вправо
		}
		while ((mas[start] <= elem) && (start < end)) //пока начальный элемент массива меньше опорного
			start++; //сдвигаем левую границу вправо
		if (start != end) //границы не сомкнулись
		{
			mas[end] = mas[start]; //перемещаем элемент [end] на место разрешающего
			end--;//сдвигаем правую границу влевоw
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
	srand(time(NULL)); //автоматическая рандомизация на основе текущего времени
	setlocale(LC_ALL, "Russian");//русская локализация консоли
	int size; //размер массива
	int* mas; //указатель на массив
	int i;    //счетчик цикла
	cout << "Введите размер массива: ";//
	cin >> size;					   //ввод размеры массива с клавиатуры
	cout << "\n";				       //
	int* mas1 = new int[size];//запрашивает нажатие любой клавиши для продолжения работы
	ofstream out; //поток для записи
	out.open("mas.txt"); //открываем файл для записи
	if (out.is_open()) { //если файл открыт
		for (i = 0; i < size; i++) { //цикл i от 0 до размера массива
			mas1[i] = 1 + rand() % 1000; //запись в i-ый элемент массива случайное число от 1 до 1000
			out << mas1[i] << '\n'; //запись i-ого элемента массива в файл с новой строки
		}
	}
	out.close(); //закрываем файл
	time_t start = clock(); //время до сортировки
	qsortRec(mas1, 0, size - 1);              //вызов функции сортировки
	time_t stop = clock();             //время после сортировки
	double time = (stop - start) / 1000.0;    //время сортировки
	ofstream sorted; //поток для записи 
	sorted.open("sortedmas.txt"); //открываем файл для записи
	if (sorted.is_open()) { //если файл открыт
		for (i = 0; i < size; i++) { //цикл i от 0 до размера массива
			sorted << mas1[i] << '\n'; //запись i-ого элемента отсортированного массива в файл с новой строки
		}
	}
		sorted.close(); //закрываем файл
		cout << endl << "Время выполнения сортировки – " << time << " секунд " << endl; //вывод времени выполнения сортировки
		system("pause");//запрашивает нажатие любой клавиши для продолжения работы
		return 0;
	}
