//
// Created by nitzan on 11/03/2021.
//
#include "snowman.hpp"
#include <iostream>
#include <unistd.h>
using namespace std;
int main ()
{
    for (int i = 0; i < 50; ++i) {
        cout << "\x1B[2J\x1B[H" << endl;
        cout << " "+ariel::snowman(12341234) +"\n\n "+ariel::snowman(42332222) +"\n\n "+ ariel::snowman(44331144)<< endl;
        usleep(100000);
        cout << "\x1B[2J\x1B[H" << endl;
        cout << " "+ariel::snowman(12341334) +"\n\n "+ariel::snowman(42333322) +"\n\n "+ ariel::snowman(44111144)<< endl;
        usleep(100000);
    }
    ariel::snowman(55555555);
}
