#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"
using namespace std;

void Sorting() {
	int variant;
	cout << "Введіть [1] для сортування за зростанням\n";
	cout << "Введіть [2] для сортування за спаданням\n";
	q:cin >> variant;
	if (variant != 1 && variant != 2) {
		cout << "Неправильний параметр, спробуйте ще раз...\n";
		goto q;
	}
	ifstream file_read;
	file_read.open("binary.txt", ios::binary);
	if (!file_read.is_open()) cout << "Не вдалося відкрити файл!\n";
	int size;
	file_read.read((char*)&size, sizeof(float));
	int border = size;
	float* arr = new float[size];
	int k = 0;
	while (!file_read.eof()) {
		file_read.read((char*)&arr[k], sizeof(float));
		k++;
		if (k == border) break;
	}
	float value;
	switch (variant) {
	case (1): {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					value = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = value;
				}
			}
		}
		break;
	}
	case (2): {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (arr[j] < arr[j + 1]) {
					value = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = value;
				}
			}
		}
		break;
	}
	}
	file_read.close();
	ofstream file_write;
	file_write.open("binary.txt", ios::binary);
	file_write.write((char*)&size, sizeof(float));
	int i = 0;
	while (!file_write.eof()) {
		file_write.write((char*)&arr[i], sizeof(float));
		i++;
		if (i == border) break;
	}
	delete[] arr;
	file_write.close();
	cout << "Зміни збережено! Вміст файлу після змін є наступним:\n";
	ShowNumbers();
}