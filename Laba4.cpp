
#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    setlocale(0, "");

    //1 задание 
    float q; //числа последовательности
    int n; // кол-во чисел последовательности
    float m = 1; //произведение
    float max = 0, max_i = 0;
    bool f1 = 0;

    cout << "введите количество чисел последовательности ";
    cin >> n;

    if (n < 0) {
        cout << "количество чисел не может быть меньше нуля";
        return 1;
    }
    if (n == 0) {
        m = 0;
        cout << "нет чисел последовательности" << endl;
    }
    else {
        cout << "введите числа последовательности ";
    }

    for (int i = 0; i != n; i++) {
        cout << i + 1 << " => ";
        cin >> q;
        if (q != int(q)) {
            m = m * q;
            f1 = 1;
            if ((q > max) and (max == NULL) ){
                max = q;
                max_i = i + 1;
            }
        }
    }
    if (f1 == 0) {
        cout << "произведение = 0" << endl;
    }
    if (f1 == 1) {
        cout << "произведение = " << m << endl;
        cout << "наибольшее из чисел = " << max << endl;
        cout << "его номер в последовательности = " << max_i << endl;
    }
    if (max == NULL) {
        max = 0;
    }




    //2 задание
    int x = -123, y, p = 1;
    x = abs(x);
    while (x != 0) {
        y = x % 10;
        p = p * y;
        x = x / 10;
    }
    cout << "произведение цифр равно " << p << endl;

    //доп
    int z;
    cout << "введите количество чисел в последовательности ";
    cin >> z;

    int sum_nchet = 0;
    int sum_chet = 0;

    if (n < 0) {
        cout << "количество чисел не может быть меньше нуля";
        return 1;
    }
    if (n == 0) {
        m = 0;
    }
    else {
        cout << "введите числа последовательности";
    }

    for (int i = 0; i != z; i++) {
        int w; //числа последовательности
        cout << i + 1 << " => ";
        cin >> w;

        if (i % 2 == 0) {
            sum_chet += w;
        }
        else {
            sum_nchet += w;
        }
    }

    int r = sum_chet - sum_nchet;

    cout << "сумма на нечетных позициях = " << sum_chet << endl;
    cout << "сумма на четных позициях = " << sum_nchet << endl;
    cout << "значение выражения = " << r << endl;

    return 0;
}