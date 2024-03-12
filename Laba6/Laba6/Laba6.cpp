#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;


int main() {
    //использование кириллицы
    system("chcp 1251");
    setlocale(LC_ALL, "RUSSIAN");
    //1
    char str[] = "Это тесТОвая Строка;";
    int i = 0;
    bool c = false;
    cout << "Начальная строка --> " << str << endl;
    cout << "Введите искомый символ ";
    char arr;
    cin >> arr;
    cout << "Позиция искомого символа в строке: ";
    char z;
    if (arr == 'ё') {
        z = 'Ё';
    }
    if (arr == 'Ё') {
        z = 'ё';
    }
    if (((char)((int)arr) < -32) and ((char)((int)arr) > -65)) {
        z = (char)((int)arr + 32);
    }
    else {
        z = (char)((int)arr - 32);
    }

    //идем по строке для нахождения символа
    while (str[i] != '\0') {
        //проверка строки
        bool fl = false;
        if (str[i] == arr) {
            fl = true;
        }
        if (str[i] == z) {
            fl = true;
        }
        if (fl) {
            //изменение строки
            str[i] = 'X';
            c = true;
            cout << i + 1 << " ";
        }
        i += 1;
    }
    //вывод измененной строки
    if (c) {
        cout << endl << "Измененная строка --> " << str << endl;
    }
    else {
        cout << "отсутсвует" << endl;
        cout << "Такого символа в строке нет" << endl;
    }




    //2
    int N; // кол-во слов мин длины

    //получение кол-во слов и букв из инпута
    ifstream in("input.txt");
    //проверка наличия файла
    if (!in.is_open()) {
        //если файла нет, то получаем с консоли
        cout << "нет файла" << "\nвведите количество в консоль" << endl;
        cout << "N =";
        cin >> N;
        if (N > 10 || N < 1) {
            cout << "WRONG N";
            return 1;
        }
    }
    else {
        //если файл присутствует, получаем данные
        in >> N;
        //если кол-во слов абсурдно
        if (N > 10 || N < 1) {
            cout << "WRONG N";
            return 1;
        }
        //вывод для проверки
        cout << endl << "N = " << N << endl;
        in.close();
    }

    //получение текста
    ifstream txt("text.txt");
    //проверка наличия текста
    if (!txt.is_open()) {
        cout << "ТЕКСТА НЕТ";
        return 1;
    }
    else {
        string words[10]; //массив слов
        int num_arr[10]; // массив длин слов
        string word; //слово из текста
        string znaki(".,:?-();!\"'"); // + ... '' "" строка символов
        string chk("уеъыьаоэяию"); // массив проверяемых букв
        int i = 0; //номер слова в массиве слов

        while (!txt.eof()) {
            int len = 0;// номер символа в слове
            int count = 0;// кол-во гласных в текущем слове
            txt >> word;
            for (int j = 0; j < size(word); j++) {
                word[j] = tolower(word[j]);
            }
            //избавляемся от знаков препинания в начале
            while (znaki.find(word[0]) != string::npos) {
                word.erase(0, 1);
            }
            //избавляемся от знаков препинания в конце
            while (znaki.find(word[size(word) - 1]) != string::npos) {
                word.erase(size(word) - 1, 1);
            }


            /*
            избавляется от всех знаков препинания
            bool flag = true;
            while(flag){
                flag = false;
                for(int j = 0;j<size(word);j++){
                    if(znaki.find(word[j]) != string::npos){
                        word.erase(j,1);
                        flag = true;
                    }
                }
            }
            */
            while (i< size(word)){
                bool f1 = false;
                int len = 0;
                while (znaki[len] != '\0') {
                    if (word[i] == znaki[len])
                        f1 = true;
                    len += 1;
                }
                if (f1) {
                    word[i] = 'x';
                }
                i += 1;
            }

            //считаем кол-во гласных
            while (word[len] != '\0') {
                if (chk.find(word[len]) != string::npos)
                    count += 1;
                len++;
            }
            //работаем с массивом
            if (i < N) {
                if (end(words) == find(begin(words), end(words), word)) {
                    words[i] = word;
                    num_arr[i] = count;
                    i++;
                }
            }
            else { //если места уже нет
                bool fl1 = true;
                while (fl1) {
                    fl1 = false;
                    for (int a = 1; a < N; a++) {
                        if (num_arr[a] < num_arr[a - 1]) {
                            swap(words[a], words[a - 1]);
                            swap(num_arr[a], num_arr[a - 1]);
                            fl1 = true;
                        }
                    }
                }
                //сравниваем кол-во гласных слов в массиве с кол-во в текущем слове
                for (int b = 0; b < N; b++) {
                    if (count > num_arr[b]) {
                        if (end(words) == find(begin(words), end(words), word)) {
                            words[b] = word;
                            num_arr[b] = count;
                            break;
                        }
                    }
                }
            }
        }
        //сортировка в порядке убывания перед выводом
        bool fl1 = true;
        while (fl1) {
            fl1 = false;
            for (int a = 1; a < N; a++) {
                if (num_arr[a] > num_arr[a - 1]) {
                    swap(words[a], words[a - 1]);
                    swap(num_arr[a], num_arr[a - 1]);
                    fl1 = true;
                }
            }
        }
        //открытие вывода
        ofstream out("result.txt");
        for (int g = 0; g < N; g++) {
            if (num_arr[g] != 0) {
                cout << words[g] << " --> " << num_arr[g] << endl;
                out << words[g] << " --> " << num_arr[g] << endl;
            }
        }
        out.close();
    }
    txt.close();

    return 0;


}