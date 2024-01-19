//
// Created by Mazeau, Emily on 3/15/23.
// Project Euler Problem 9
//
#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int b;
    int c;

    for (int a = 1; a < 1000; a++) {
        b = (1000 * (500 - a))/(1000-a);
        if (b < 0) {
            break;
        }
        c = 1000 - a - b;
        if (c < 0) {
            break;
        }
        if (pow(a, 2) + pow(b, 2) == pow(c,2)) {
            cout << a * b * c;
            break;
        }
    }
    return 0;
}