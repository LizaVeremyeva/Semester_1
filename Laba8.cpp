#include <iostream>
#include <math.h>
using namespace std;
namespace mt {
	// Функция для расчета нормы матрицы
	int calculateNorm(int** matrix, int rows, int cols) {
		int maxSum = INT_MIN;
		for (int i = 0; i < cols; i++) {
			int sum = 0;
			for (int j = 0; j < rows; j++) {
				sum += abs(matrix[j][i]);
			}
			if (maxSum < sum) {
				maxSum = sum;
			}
		}
		return maxSum;
	}

	void output(int** A, int M, int N) {
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++) {
				std::cout << A[i][j] << "\t";
			}
			std::cout << endl;
		}
	}
}
int main()
{//процедура
	setlocale(LC_ALL, "RU");
	//1

	int K; 
	cout << "Введите длину массива: ";
	cin >> K;
	if (K < 0)
		cout << "Длина массива не может быть отрицательной";
	else {
		int* A = (int*)calloc(K, sizeof(int)); // создаем динамический массив
		for (int i = 0; i < K; i++) // заполняем массив цифрами по условию
			A[i] = i + 1;
		cout << "Исходный массив\n";
		for (int i = 0; i < K; i++)
			cout << A[i] << " ";
		int S;
		cout << endl << "Введите количество чисел, которое вы хотите ввести: ";
		cin >> S;
		if (K + S < 0)
			cout << "Ошибка, длина массива не может быть отрицательной";
		else {
			K = K + S;
			int* A1 = (int*)realloc(A, K * sizeof(int));// Изменяем длину массива на заданную пользователем
			if (S < 0) {
				cout << "Вы срезали массив" << endl;
				for (int i = 0; i < K; i++)
					cout << A1[i] << " ";
				free(A1);
				return 0;
			}
			cout << "Введите " << S << " чисел \n";
			bool flag = false;
			int max = INT_MIN;
			int q;
			for (int i = K - S; i < K; i++) // проверка есть ли среди новых чисел отрицательное
			{
				cin >> A1[i];
				if (A1[i] > max)
				{
					max = A1[i];
					q = i;
				}				
			}
			if (max % 2 != 0)
				A1[q] = A1[q] * 100;
			cout << "Массив после преобразования" << endl;
			for (int i = 0; i < K; i++)
				cout << A1[i] << " ";
			free(A1);
			}
	}
	cout << endl;

	//2 

	int M, N;
	cout << "Введите размеры матрицы сначала строки, затем столбцы: ";
	cin >> M >> N;

	//заполнение матрицы A
	int** A = new int* [M];
	for (int i = 0; i < M; i++) {
		A[i] = new int[N];
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = 10 * (i + 1) + (j + 1);
		}
	}

	// Вывод изначальной матрицы
	cout << "Изначальная матрица" << endl;
	mt::output(A, M, N);

	// Расчет нормы матрицы A
	int defA = mt::calculateNorm(A, M, N);

	//транспонирование матрицы A
	int** B = new int* [N];
	for (int i = 0; i < N; i++) {
		B[i] = new int[M];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			B[i][j] = A[j][i];
		}
	}

	// Освобождение памяти, выделенной под матрицу A
	for (int i = 0; i < M; i++) {
		delete[] A[i];
	}
	delete[] A;

	// Вывод транспонированной матрицы B
	cout << "Транспонированная матрица" << endl;
	mt::output(B, N, M);

	// Расчет нормы матрицы B
	int defB = mt::calculateNorm(B, N, M);

	// Сравнение
	cout << "Норма изначальной матрицы равна " << defA << endl << "Норма транспонированной матрицы равна " << defB << endl;

	if (defA == defB) {
		cout << "Нормы матриц равны";
	}
	else if (defA > defB) {
		cout << "Норма изначальной матрицы больше нормы транспонированной матрицы";
	}
	else {
		cout << "Норма транспонированной матрицы больше нормы изначальной";
	}
	cout << endl;

	// Освобождение памяти, выделенной под матрицу B
	for (int i = 0; i < N; i++) {
		delete[] B[i];
	}
	delete[] B;

	return 0;
}
