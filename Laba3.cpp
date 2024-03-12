
#include <iostream>
#include <math.h>
int main()
{
    //1
    int a, b, c, d;
    std::cin >> a>> b>> c;
    if ((a>0) and (b>0) and (c>0)) 
    {
        if ((a % c == 0) and (b % c == 0))
        {
            d = (a + b) / c;
            std::cout << d << "(a+b)/c" << std::endl;
        }
        else if ((a % c == 0) and (b % c != 0))
        {
            d = (a / c) + b;
            std::cout << d << std::endl;
        }
        else
        {
            d = a + b - c;
            std::cout << d << std::endl;
        }
    }
    else
    {
        std::cout << "Ошибка" << std::endl;
    }
    

    //2
    setlocale(LC_ALL, "Rus");
    int n, ost;
    std::cin >> n;
    n = n + 1;
    ost = n % 5;
    switch (ost)
    {
    case 0:
        std::cout << "Юбилей в следующем году";
        break;
    case 1:
        std::cout << "Нет юбилея в следующем году";
        break;
    case 3:
        std::cout << "Нет юбилея в следующем году";
        break;
    case 4:
        std::cout << "Нет юбилея в следующем году";
        break;
    }
}
