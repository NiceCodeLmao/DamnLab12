#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

void CreateFile(int min, int max) {
	float number;
	int x;
	cout << "������ ������ ����� ������� ��������?\n";
	cin >> x;
	ofstream file;
	file.open("binary.txt", ios::binary);
	file.write((char*)&x, sizeof(float));
	for (int i = 0; i < x; i++) {
		number = (float)rand() / RAND_MAX * (max - min) + min;
		file.write((char*)&number, sizeof(float));
	}
	file.close();
	cout << "���� ��������! ����� �� ������ ������ ���� �����.\n\n";
}