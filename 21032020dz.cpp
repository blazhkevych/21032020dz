/*
Домашнее задание № 12 Курс «Язык программирования C»
Встреча №23
Тема : Функции.Перегрузка функций.Рекурсия.
Домашнее задание
Задание 1 : Написать перегруженные функции(int, double, char) для выполнения следующих задач : Инициализация квадратной матрицы;
Вывод матрицы на экран;
Определение максимального и минимального элемента на главной диагонали матрицы;
Сортировка элементов по возрастанию отдельно для каждой строки матрицы.
int

double

char

*/
#include <iostream>
#include <ctime>
using namespace std;
//Написать перегруженные функции (int, double, char) для выполнения следующих задач:
//Инициализация квадратной матрицы;+
//Вывод матрицы на экран;+
//Определение максимального и минимального элемента на главной диагонали матрицы;+
//Сортировка элементов по возрастанию отдельно для каждой строки матрицы.+
//int** CreateArray2D(int n, int m) // создание двумерного динамического массива
int** createArr2D(int rows, int cols) { // создание двумерного динамического массива - int
	int** mas = new int* [rows];
	for (int r = 0; r < rows; r++)
		mas[r] = new int[cols] {0};
	return mas;
}
double** createArr2Ddouble(double rows, double cols) { // создание двумерного динамического массива - double
	double** mas = new double* [rows];
	for (int r = 0; r < rows; r++)
		mas[r] = new double[cols] {0};
	return mas;
}
char** createArr2Dchar(int rows, int cols) { // создание двумерного динамического массива - char
	char** mas = new char* [rows];
	for (int r = 0; r < rows; r++)
		mas[r] = new char[cols] {0};
	return mas;
}
void SetRndArray2D(int** arr, int n, int m, int a = 1, int b = 9) // заполнение двумерного динамического массива - int
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = a + rand() % (b - a + 1);
}
void SetRndArray2Ddouble(double** arr, int n, int m, int a = 1, int b = 9) // заполнение двумерного динамического массива - double
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = a + rand() % (b - a + 1) / static_cast<double>(rand() % 10 + 1);
}
void SetRndArray2Dchar(char** arr, int n, int m) // заполнение двумерного динамического массива - char
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = 97 + rand() % 26;
}
void PrintArray2D(int** arr, int n, int m) // вывод двумерного динамического массива - int
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
}
void PrintArray2Ddouble(double** arr, int n, int m) // вывод двумерного динамического массива - double
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
}
void PrintArray2Dchar(char** arr, int n, int m) // вывод двумерного динамического массива - char
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
}
void SortingArray2D(int** arr, int n, int m) // сортировка двумерного динамического массива - int
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			int index = j;
			int minElement = arr[i][j];
			for (int p = j; p < m; p++)
			{
				if (minElement > arr[i][p])
				{
					index = p;
					minElement = arr[i][p];
				}
			}
			swap(arr[i][j], arr[i][index]);
		}
	}
}
void SortingArray2Ddouble(double** arr, int n, int m) // сортировка двумерного динамического массива - double
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			int index = j;
			double minElement = arr[i][j];
			for (int p = j; p < m; p++)
			{
				if (minElement > arr[i][p])
				{
					index = p;
					minElement = arr[i][p];
				}
			}
			swap(arr[i][j], arr[i][index]);
		}
	}
}
void SortingArray2Dchar(char** arr, int n, int m) // сортировка двумерного динамического массива - char
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			int index = j;
			int minElement = arr[i][j];
			for (int p = j; p < m; p++)
			{
				if (minElement > arr[i][p])
				{
					index = p;
					minElement = arr[i][p];
				}
			}
			swap(arr[i][j], arr[i][index]);
		}
	}
}
int MinElOnTheMainDiagonalArray2D(int** arr, int n) // определение минимального элемента на главной диагонали матрицы - int
{
	int min = arr[0][0];
	for (int i = 1; i < n; i++)
		if (min > arr[i][i]) min = arr[i][i];
	return min;
}
double MinElOnTheMainDiagonalArray2Ddouble(double** arr, int n) // определение минимального элемента на главной диагонали матрицы - double
{
	double min = arr[0][0];
	for (int i = 1; i < n; i++)
		if (min > arr[i][i]) min = arr[i][i];
	return min;
}
char MinElOnTheMainDiagonalArray2Dchar(char** arr, int n) // определение минимального элемента на главной диагонали матрицы - char
{
	int min = arr[0][0];
	for (int i = 1; i < n; i++)
		if (min > arr[i][i]) min = arr[i][i];
	return min;
}
int MaxElOnTheMainDiagonalArray2D(int** arr, int n) // определение максимального элемента на главной диагонали матрицы - int
{
	int max = arr[0][0];
	for (int i = 1; i < n; i++)
		if (max < arr[i][i]) max = arr[i][i];
	return max;
}
double MaxElOnTheMainDiagonalArray2Ddouble(double** arr, int n) // определение максимального элемента на главной диагонали матрицы - double
{
	double max = arr[0][0];
	for (int i = 1; i < n; i++)
		if (max < arr[i][i]) max = arr[i][i];
	return max;
}
char MaxElOnTheMainDiagonalArray2Dchar(char** arr, int n) // определение максимального элемента на главной диагонали матрицы - char
{
	int max = arr[0][0];
	for (int i = 1; i < n; i++)
		if (max < arr[i][i]) max = arr[i][i];
	return max;
}
void DeleteArray2D(int** arr, int n) // удаление двумерного динамического массива - int
{
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
}
void DeleteArray2Ddouble(double** arr, int n) // удаление двумерного динамического массива - double
{
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
}
void DeleteArray2Dchar(char** arr, int n) // удаление двумерного динамического массива - char
{
	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
}
int main()
{
	// char работает
	int n = 4, m = n;
	char** arr = createArr2Dchar(n, m);
	srand(time(0));
	SetRndArray2Dchar(arr, n, m);
	cout << "Source array:\n";
	PrintArray2Dchar(arr, n, m);
	SortingArray2Dchar(arr, n, m);
	cout << "Sorted array:\n";
	PrintArray2Dchar(arr, n, m);
	cout << "Minimal element on the main diagonal of the matrix: " << MinElOnTheMainDiagonalArray2Dchar(arr, n) << endl;
	cout << "Maximum element on the main diagonal of the matrix: " << MaxElOnTheMainDiagonalArray2Dchar(arr, n) << endl;
	DeleteArray2Dchar(arr, n);
	/*
	// double работает
	int n = 4, m = n;
	double** arr = createArr2Ddouble(n, m);
	srand(time(0));
	SetRndArray2Ddouble(arr, n, m);
	cout << "Source array:\n";
	PrintArray2Ddouble(arr, n, m);
	SortingArray2Ddouble(arr, n, m);
	cout << "Sorted array:\n";
	PrintArray2Ddouble(arr, n, m);
	cout << "Minimal element on the main diagonal of the matrix: " << MinElOnTheMainDiagonalArray2Ddouble(arr, n) << endl;
	cout << "Maximum element on the main diagonal of the matrix: " << MaxElOnTheMainDiagonalArray2Ddouble(arr, n) << endl;
	DeleteArray2Ddouble(arr, n);
	*/
	/*
	// int работает
	int n = 4, m = n;
	int** arr = createArr2D(n, m);
	srand(time(0));
	SetRndArray2D(arr, n, m);
	cout << "Source array:\n";
	PrintArray2D(arr, n, m);
	SortingArray2D(arr, n, m);
	cout << "Sorted array:\n";
	PrintArray2D(arr, n, m);
	cout << "Minimal element on the main diagonal of the matrix: " << MinElOnTheMainDiagonalArray2D(arr, n) << endl;
	cout << "Maximum element on the main diagonal of the matrix: " << MaxElOnTheMainDiagonalArray2D(arr, n) << endl;
	DeleteArray2D(arr, n);
	*/
}
/*
Задание 2: Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел.
#include <iostream>
using namespace std;
size_t gcd(size_t a, size_t b)
{
	if (b == 0)
		return a;
	if (a > b)
		return gcd(b, a % b);
	else
		return gcd(a, b % a);
}

int main()
{
	int a = 54, b = 24;
	cout << gcd(a, b) << endl;
}
*/
/*
Задание 3: Написать игру «Быки и коровы».Программа "загадывает" четырёхзначное число и играющий должен угадать его.После ввода пользователем числа программа сообщает, сколько цифр числа угадано(быки) и сколько цифр угадано и стоит на нужном месте(коровы).После отгадывания числа на экран необходимо вывести количество сделанных пользователем попыток.В программе необходимо использовать рекурсию.
#include <iostream>
#include <time.h>
using namespace std;
int* m = new int[4];
int* q = new int[4];
static int sproba = 0;
int* randNumber()
{
	for (int i = 0; i < 4; i++)
		*(m + i) = rand() % 10;
	return m;
}
int* digits(int n)
{
	for (int i = 3; i >= 0; i--)
	{
		*(q + i) = n % 10;
		n /= 10;
	}
	return q;
}
void Count(int* x, int* y, int n, int* bull, int* cow)
{
	*bull = *cow = 0;
	for (int i = 0; i < n; i++)
		if (*(x + i) == *(y + i))
			(*bull)++;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((*(x + i) == *(y + j)) && (i != j))
				(*cow)++;
}
void game(int* r, int* N)
{
	*N = sproba;
	cout << "Input your number: ";
	int number;
	cin >> number;
	int* b = digits(number);
	int bull, cow;
	Count(r, b, 4, &bull, &cow);
	cout << "Bulls = " << bull << ", cows = " << cow << endl;
	sproba++;
	if (bull == 4) cout << "OK!\n";
	else game(r, N);
}
void main()
{
	int m = 0;
	srand(time(NULL));
	int* a = randNumber();
	game(a, &m);
	cout << "Winning in " << m << " moves!\n";
}
*/