#include <iostream>
#include <math.h>

int main()
{
    unsigned char y, x; //5=0b00000101
    int i, a, x1;
    x = 5;

    std::cin >> i;

    y = int(pow(2, i));
    x1 = x & y;
    a = x1/pow(2, i);

    std::cout << a;

    /*
    5 = 0b0101
    Пусть i = 2
    2^2 01000
    0101 & 0100 = 1
    1/(2^2) = 1
    */ 

}

