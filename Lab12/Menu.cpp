#include <iostream>
#include "Functions.h"
using namespace std;

void Menu(int &n) {
	const int min = -10;
	const int max = 10;
	cout << "������ [1] ��� ��������� ������ �������� �����\n";
	cout << "������ [2] ��� ��������� � ����� ���������� �����\n";
	cout << "������ [3] ��� ����������� �������� �����\n";
	cout << "������ [4] ��� ���������� ����� ����� ������ ���������\n";
	cout << "������ [5] ��� ������ ����� ����� ���� �����\n";
	cout << "������ [6] ��� ��������� ����� ����� ���� �����\n";
	cout << "������ [0] ��� ���������� ������ ��������\n";
	q:cin >> n;
	if (n < 0 || n > 6) {
		cout << "������������ ��������, ��������� �� ���...\n";
		goto q;
	}
	switch (n) {
		case (0):
			break;
		case(1): {
			CreateFile(min, max);
			break;
		}
		case(2): {
			ShowNumbers();
			break;
		}
		case(3): {
			EditFile();
			break;
		}
		case(4): {
			Sorting();
			break;
		}
		case(5): {
			Selection();
			break;
		}
		case(6): {
			DeleteNumbers();
			break;
		}
	}
}