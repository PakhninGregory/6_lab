#include <iostream>
#include <ctime> 
#include <iomanip> 
#include <string>
using namespace std;
#define Debug "PressF"

double min(int x, int y, int z) {
	if (x < y and z < y)
		return y;
	else if (x < z and y < z)
		return z;
	else
		return x;

}


// часть А
 int Menu(int* left, int* right, double* z) {
	cout << "\nДоступные действия:\n\n";

	cout << "1: Ввод верхнего предела\t";
	cout << "2: Ввод нижнего предела\n";
	cout << "3: Повторный ввод числа\t";
	cout << "Ввод любого иного варианта для выхода из программы\t";
	int k;
	cin >> k;
	switch (k) {
	case 1: {
		cout << "1: Ввод верхнего предела\t";
		cin >> *left;
	} 
		  break;
	case 2:{
		cout << "2: Ввод нижнего предела\n";
		cin >> *right;
	}
		  break;
	case 3:{
		cout << "3: Повторный ввод числа\t";
		cin >> *z;
	}
	break;
	};
	return 0;
};

int predel(int* left, int* right) {

	double z;
	cout << "Введите число\n";
	cin >> z; //считываем число
	if (int(z) != z) exit(1);
	while (z<*left || z>*right) Menu(left, right, &z);
	if (z>=*left || z<=*right) return z;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int z;
	do {
		cout << "Введите номер задания для его дальнейшего выполнения (для выхода - 0): ";
		cin >> z;
		switch (z) {
		case 1: {
			cout << "Функция возвращает наибольшее из 3 int\n";
			cout << "Введите три числа: \n\n";
			int x, y, z;
			cin >> x >> y >> z;
			cout << "Наибольшее: " << min(x, y, z) << '\n';
		}
			  break;
		case 2: {
			cout << "Введите пределы\n";
			int a, b;
			cin >> a >> b;
			cout << a << "<" << predel(&a, &b) << "<" << b << endl;
		}
			  break;

		case 3: {
			cout << "Реализуйте сортировку массива вставками.(массив из целых чисел).\n";
			srand((int)time(0));
			int n;
			do
			{
				cout << "Enter n: "; cin >> n;
				if (n < 2 || n >= 8) {
					cout << "введите 2<=n<8 ...\n";
					system("pause");
					system("cls");
				}
			} while (n < 1 || n >= 8);
			int* arr = new int[n];

			for (int i = 0; i < n; i++)
			{
				arr[i] = rand() % 100;
				cout << arr[i] << "\t";
			}
			cout << endl;
			int fict;
			for (int i = 0, j; i < n; i++)
			{
				fict = arr[i];
				for (j = i - 1; j >= 0 && arr[j] > fict; j--)
					arr[j + 1] = arr[j];
				arr[j + 1] = fict;
			}

			for (int i = 0; i < n; i++)
				cout << arr[i] << "\t";
			cout << endl;
			delete[]arr;
		}
			  break;

		}

		system("pause");
		system("cls");
	} while (z != 0);
	cout << "\n\n\n\n\t\t\tСделал Пахнин Григорий\n\n\n\n\n";
	return 0;
}