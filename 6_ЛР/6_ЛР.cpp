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
	cout << "Ввод любого иного варианта для выхода из программы";
	int k;
	cin >> k;
	switch (k) {
	case 1: cin >> *left;
	case 2: cin >> *right;
	case 3: cin >> *z;
	default: exit(1);
	};
};

int predel(int left, int right) {

	double z;
	cin >> z; //считываем число
	if (int(z) != z) exit(1);
	if (z<left || z>right) Menu(&left, &right, &z);
	else return z;
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
			cout << "Введите два числа: \n\n";
			int x, y, z;
			cin >> x >> y >> z;
			cout << "Наибольшее: " << min(x, y, z) << '\n';
		}
			  break;
		case 2: {
			cout << "Расчет определителя матрицы, матрица размером 3 на 3. Ввод чисел построчно. Числа только целые.\n";
			int a, b;
			cin >> a >> b;
			cout << "]e]" << predel(a, b) << endl;
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