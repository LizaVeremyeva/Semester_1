
#include <iostream>
using namespace std;
#include <math.h>

int main()
{
    setlocale(0, "");
    //1
    int const k = 19;
    int mass[k];
    int n2, x;
    bool f = 1;
    cout << "введите длину последовательности" << endl;
    cin >> n2;
    if ((n2 < 0) or (n2 >= 20)) {
        cout << "неверная длина" << endl;
        return 1;
    }
    cout << "введите числа" << endl;
    for (int i = 1; i <= n2; i++) {
        cin >> mass[i];
        if (mass[i] % 5 != 0) {
            f = 0;
        }
    }
    bool swapped = true;
    if (f == 1) {
        while (swapped) {
            swapped = false;
            for (int i = 1; i <= n2; i++) {
                if (mass[i] < mass[i - 1]) {
                    swap(mass[i], mass[i - 1]);
                    swapped = true;
                }
            }
        }
    }
    for (int i = 1; i <= n2; i++) {
        cout << mass[i] << " ";
    }


    //2  
    int const m1 = 9, n1 = 9;
    int mass1[m1][n1];
    int m, n;
    cout << "введите длину и ширину матрицы" << endl;
    cin >> m;
    cin >> n;
    if ((m < 0) or (m > 9) or (n < 0) or (n > 9)) {
        cout << "неверная длина или ширина" << endl;
        return 1;
    }
    cout << "введите числа" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mass1[j][i];
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mass1[j][i] << " ";
        }
        cout << "\n";
    }
    int maxColumnSum = 0;
    int maxColumnIndex = 0;

    for (int i = 0; i < n; ++i) {
        int columnSum = 0;
        for (int j = 0; j < m; ++j) {
            columnSum += mass1[j][i];
        }
        if (abs(columnSum) >= maxColumnSum) {
            maxColumnSum = abs(columnSum);
            maxColumnIndex = i;
        }
    }

    cout << "Строка с максимальной суммой: " << maxColumnIndex + 1 << endl;

    for (int j = 0; j < n; ++j) {
        mass1[j][maxColumnIndex] = 999;
    }

    cout << "Матрица после изменения строки:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mass1[j][i] << " ";
        }
        cout << "\n";
    }


    return 0;

}
