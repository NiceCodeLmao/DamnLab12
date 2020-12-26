#include <iostream>
#include <fstream>
#include "Functions.h"
using namespace std;

void DeleteNumbers() {
	float value;
	int variant;
	cout << "������ �������� ��� ���������\n";
	cin >> value;
	cout << "������ [1], ��� �������� ����� ��������\n";
	cout << "������ [2], ��� �������� ����� ��������\n";
	q:cin >> variant;
	if (variant != 1 && variant != 2) {
		cout << "������������ ��������, ��������� �� ���...\n";
		goto q;
	}
	ifstream file_read;
	file_read.open("binary.txt", ios::binary);
	if (!file_read.is_open()) cout << "�� ������� ������� ����!\n";
	int size, temp = 0;
	file_read.read((char*)&size, sizeof(float));
	int border = size;
	float* arr = new float[size];
	int k = 0;
	for (int i = 0; i < border; i++) {
		file_read.read((char*)&arr[i], sizeof(float));
	}
	file_read.close();
	ofstream file_write;
	file_write.open("binary.txt", ios::binary);
	if (!file_write.is_open()) cout << "�� ������� ������� ����!\n";
	file_write.write((char*)&size, sizeof(float));
	switch (variant){
		case(1): {
			for (int i = 0; i < size; i++) {
				if (arr[i] < value)
					file_write.write((char*)&arr[i], sizeof(float));
				else continue;
			}
			break;
		}
		case(2): {
			for (int i = 0; i < size; i++) {
				if (arr[i] > value)
					file_write.write((char*)&arr[i], sizeof(float));
				else continue;
			}
			break;
		}
	}
	delete[] arr;
	file_write.close();
	cout << "���� ���������!\n";
	ShowNumbers();
}