
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <locale.h>
#include <iostream>
#include <fstream>

using namespace std;



void qsortRec(int* mas, int start, int end) {
	int elem = mas[start]; //������� �������
	int i = start; //������ �������
	int j = end; //����� �������

	while (start < end) { //���� ������� �� ���������
		while ((mas[end] >= elem) && (start < end)) //���� �������� ������� ������� ������ ��������
			end--; //�������� ������ ������� �����
		if (start != end) //������� �� ����������
		{
			mas[start] = mas[end]; //���������� ������� [start] �� ����� ������������
			start++;//�������� ����� ������� ������
		}
		while ((mas[start] <= elem) && (start < end)) //���� ��������� ������� ������� ������ ��������
			start++; //�������� ����� ������� ������
		if (start != end) //������� �� ����������
		{
			mas[end] = mas[start]; //���������� ������� [end] �� ����� ������������
			end--;//�������� ������ ������� �����w
		}
	}

	mas[start] = elem;
	elem = start;
	start = i;
	end = j;
	//����������� ������, ���� ��������, ��� �����������
	if (start < elem) {
		//"����� �����"
		qsortRec(mas, start, elem - 1);
	}
	if (end > elem) {
		//"������ �����"
		qsortRec(mas, elem + 1, end);
	}
}

int main() {
	srand(time(NULL)); //�������������� ������������ �� ������ �������� �������
	setlocale(LC_ALL, "Russian");//������� ����������� �������
	int size; //������ �������
	int* mas; //��������� �� ������
	int i;    //������� �����
	string filename1 = "mas.txt"; //��� ����� ��������� �������
	string filename2 = "sortedmas.txt"; // ��� ����� ���������������� �������
	cout << "\t\t\t\t\t" << "��������� ������� ����������" << endl;
	cout << "������� ������ �������(>1): ";//
	cin >> size;					      //���� ������� ������� � ����������
	cout << "\n";					     //	
	while(size <= 1){ // �������� ����� �� ������ 1 � ������
		system("cls"); // ������� �������
		cout << "\t\t\t\t\t" << "��������� ������� ����������" << endl;
		cout << "������ �� ����� ���� <= 1, ������� �����: "; //
		cin >> size;										  //��������� ���� ������� �������
		cout << "\n";
		}
	int* mas1 = new int[size];//��������� ������ ��� �������
	ofstream out; //����� ��� ������
	out.open(filename1); //��������� ���� ��� ������
	if (out.is_open()) { //���� ���� ������
		cout << "��������� ������� � ������ � ����...";

		for (i = 0; i < size; i++) { //���� i �� 0 �� ������� �������
			mas1[i] = (rand() % 10000) - 5000; //������ � i-�� ������� ������� ��������� ����� �� -5000 �� 5000
			out << mas1[i] << '\n'; //������ i-��� �������� ������� � ���� � ����� ������

		}
	}
	
	system("cls");
	cout << "\t\t\t\t" << "��������� ������� ����������" << endl;
	cout << "��������� ���������, ������ �������� " << size << " ������� � " << filename1 << endl;
	cout << endl << "���������...";
	out.close(); //��������� ����
	time_t start = clock(); //����� �� ����������
	qsortRec(mas1, 0, size - 1);              //����� ������� ����������
	time_t stop = clock();             //����� ����� ����������
	double time = (stop - start) / 1000.0;    //����� ����������
	ofstream sorted; //����� ��� ������ 
	sorted.open(filename2); //��������� ���� ��� ������
	if (sorted.is_open()) { //���� ���� ������
		for (i = 0; i < size; i++) { //���� i �� 0 �� ������� �������
			sorted << mas1[i] << '\n'; //������ i-��� �������� ���������������� ������� � ���� � ����� ������
		}
	}
		sorted.close(); //��������� ����
		system("cls");
		cout << "\t\t\t\t\t" << "��������� ������� ����������" << endl;
		cout << "���������� ���������, �������� ������ �������� " << size << " ������� � " << filename1 << endl;
		cout << "�������������� ������ ������� � " << filename2 << endl;
		cout << endl << "����� ���������� ���������� � " << time << " ������ " << endl; //����� ������� ���������� ����������
		getchar();//����������� ������� ����� ������� ��� ����������� ������
		return 0;
	}
