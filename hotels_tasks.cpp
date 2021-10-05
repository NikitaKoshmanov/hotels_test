#include <iostream>
#include <string>
#include <locale.h>
#include <stdlib.h>
#include <map>
using namespace std;

void task1(string array[], int x) { // task 1 , 10 min
	string str;
	for (int i = 0; i < x; i++) {
		if (i != x - 1)
			str = str + array[i] + ", ";
		else str = str + array[i] + '.';
	}
	cout << "Полученная строка:" << endl;
	cout << str << endl;
}

void task2(float x) { // task 2 , 30 min
	int y = round(x);
	int z = y % 5;
	if (z < 2.5)
		y = y - z;
	else y = y - z + 5;
	cout << "Округлённое число:" << endl;
	cout << y << endl;
}

void task3(int x) { // task 3 , 15 min
	string str;
	int ost;
	ost = x % 100;
	if (ost >= 10 && ost <= 19) {
		str = to_string(x) + " комьютеров";
		cout << str << endl;
		return;
	}
	ost = x % 10;
	if (ost == 1)
		str = to_string(x) + " комьютер";
	else if (ost >= 2 && ost <= 4)
		str = to_string(x) + " комьютера";
	else 
		str = to_string(x) + " комьютеров";
	cout << str << endl;
}

void task4(int pr) { // task 4 , 15 min
	for (int i = 2; i <= sqrt(pr); i++) {
		if (pr % i == 0) {
			cout << "Число не является простым" << endl;
			return;
		}
	}
	cout << "Число простое" << endl;
}

int comp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

void task5(int mass1[], int x, int mass2[], int y) { // task 5 , 2 hour
	map<int, int> m;
	for (int i = 0; i < x; i++)
		if (mass1[i] == mass1[i + 1])
			++m[mass1[i]];
	for (int i = 0; i < y; i++)
		if (mass2[i] == mass2[i + 1])
			++m[mass2[i]];
	for (std::map<int, int>::iterator i = m.begin(); i != m.end(); i++)
		if ((*i).second > 1)
			cout << (*i).first << ' ';
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите номер задания:" << endl;
	int number;
	cin >> number;
	switch (number) {
	case 1: {
		cout << "Введите количество городов:" << endl;
		int number_of_cities;
		cin >> number_of_cities;
		string* array = new string[number_of_cities];
		cout << "Введите города на латинице(каждый с новой строки):" << endl;
		for (int i = 0; i < number_of_cities; i++) {
			cin >> array[i];
		}
		task1(array, number_of_cities);
		break; 
	}
	case 2:
		cout << "Введите число, которое хотите округлить:" << endl;
		float x;
		cin >> x;
		task2(x);
		break;
	case 3:
		int b;
		cout << "Введите количество компьютеров:" << endl;
		cin >> b;
		task3(b);
		break;
	case 4:
		int pr;
		cout << "Проверка числа на простое или нет:" << endl;
		cin >> pr;
		task4(pr);
		break;
	case 5: {
		int i;
		cout << "Количество чисел в первом массиве:" << endl;
		cin >> i;
		int* mass1 = new int[i];
		cout << "Введите числа массива(каждый с новой строки):" << endl;
		for (int i1 = 0; i1 < i; i1++) {
			cin >> mass1[i1];
		}
		int j;
		cout << "Количество чисел во втором массиве:" << endl;
		cin >> j;
		int* mass2 = new int[j];
		cout << "Введите числа массива(каждый с новой строки):" << endl;
		for (int j1 = 0; j1 < j; j1++) {
			cin >> mass2[j1];
		}
		qsort(mass1, i, sizeof(int), comp);
		qsort(mass2, j, sizeof(int), comp);
		task5(mass1, i, mass2, j);
		break;
	}
	default:
		cout << "Введен неккоректный номер задания!" << endl;
		break;
	}
}