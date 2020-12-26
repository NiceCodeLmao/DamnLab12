#include <iostream>
#include <fstream>
using namespace std;

void ShowNumbers() {
	float temp;
	int i = 0;
	ifstream file;
	file.open("binary.txt", ios::binary);
	cout << "Вміст бінарного файлу є наступним:\n";
	do {
		file.read((char*)&temp, sizeof(float));
		i++;
		if (i == 1)
			continue;
		if(!file.eof())
		cout << temp << " ";
	} while (!file.eof());

	cout << endl << endl;
	file.close();
}