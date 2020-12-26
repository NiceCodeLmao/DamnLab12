#include <iostream>
#include "Functions.h"
using namespace std;

void Menu(int &n) {
	const int min = -10;
	const int max = 10;
	cout << "Введіть [1] для створення нового бінарного файлу\n";
	cout << "Введіть [2] для перегляду в даних створеного файлу\n";
	cout << "Введіть [3] для редагування бінарного файлу\n";
	cout << "Введіть [4] для сортування даних згідно вашого параметру\n";
	cout << "Введіть [5] для відбору даних згідно вашої умови\n";
	cout << "Введіть [6] для видалення даних згідно вашої умови\n";
	cout << "Введіть [0] для завершення роботи програми\n";
	q:cin >> n;
	if (n < 0 || n > 6) {
		cout << "Неправильний параметр, спробуйте ще раз...\n";
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