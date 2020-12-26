#include <iostream>
#include <fstream>
#include <string>
#include "Functions.h"
using namespace std;

void EditFile() {
	float value;
	int variant, position;
	cout << "������ [1] ��� ������� ��������\n";
	cout << "������ [2] ��� ��������� ��������\n";
    q:cin >> variant;
	if (variant != 1 && variant != 2) {
		cout << "������������ ��������, ��������� �� ���...\n";
		goto q;
	}
	switch (variant) {
		case (1): {
			cout << "������ ������� ��� ������\n";
			cin >> position;
			cout << "������ �������� ��������\n";
			cin >> value;
			ifstream file_read;
			file_read.open("binary.txt", ios::binary);
			if (!file_read.is_open()) cout << "�� ������� ������� ����!\n";
			int x;
			file_read.read((char*)&x, sizeof(float));
			int border = x;
			float* arr = new float[x+1];
			int i = 0;
			while (!file_read.eof()) {
				file_read.read((char*)&arr[i], sizeof(float));
				i++;
				if (i == border) break;
			}
			for (i = border--; i >= position; i--) {
				arr[i] = arr[i - 1];
			}
			arr[position-1] = value;
			x++;
			file_read.close();
			ofstream file_write;
			file_write.open("binary.txt", ios::binary);
			file_write.write((char*)&x, sizeof(float));
			for (i = 0; i < x; i++) {
				file_write.write((char*)&arr[i], sizeof(float));
			}
			break;
		}
		case (2): {
			cout << "������ ������� ��� ���������\n";
			cin >> position;
			position--;
			ifstream file_read;
			file_read.open("binary.txt", ios::binary);
			if (!file_read.is_open()) cout << "�� ������� ������� ����!\n";
			int x;
			file_read.read((char*)&x, sizeof(float));
			int border = x;
			float* arr = new float[x];
			int i = 0;
			while (!file_read.eof()) {
				file_read.read((char*)&arr[i], sizeof(float));
				i++;
				if (i == border) break;
			}
			file_read.close();
			ofstream file_write;
			file_write.open("binary.txt", ios::binary);
			x--;
			file_write.write((char*)&x, sizeof(float));
			for (i = 0; i <= x; i++) {
				if (i != (position)) file_write.write((char*)&arr[i], sizeof(float));
				else continue;
			}
			delete[] arr;
			file_write.close();
			}
			break;
		}
	cout << "���� ���������! ���� ����� ���� ��� � ���������:\n";
	ShowNumbers();
}