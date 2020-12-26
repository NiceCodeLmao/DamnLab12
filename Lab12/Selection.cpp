#include <iostream>
#include <fstream>
using namespace std;

void Selection() {
	float value;
	int variant;
	cout << "Введіть значення для порівняння\n";
	cin >> value;
	cout << "Введіть [1], щоб відібрати більші елементи\n";
	cout << "Введіть [2], щоб відібрати менші елементи\n";
	q:cin >> variant;
	if (variant != 1 && variant != 2) {
		cout << "Неправильний параметр, спробуйте ще раз...\n";
		goto q;
	}
	ifstream file;
	file.open("binary.txt", ios::binary);
	if (!file.is_open()) cout << "Не вдалося відкрити файл!\n";
	int size;
	file.read((char*)&size, sizeof(float));
	int border = size;
	float* arr = new float[size];
	int k = 0;
	while (!file.eof()) {
		file.read((char*)&arr[k], sizeof(float));
		k++;
		if (k == border) break;
	}
	for (int i = 0; i < border; i++) {
		switch (variant) {
			case(1): {
				if (arr[i] > value) cout << arr[i] << ' ';
				break;
			}
			case(2): {
				if (arr[i] < value) cout << arr[i] << ' ';
				break;
			}
		}
	}
	cout << endl;
	delete[] arr;
	file.close();
}