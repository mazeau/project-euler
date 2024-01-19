//
// Created by Mazeau, Emily on 3/14/23.
// Project Euler Problem 5
//
#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int x = 2520;

    while (x) {
        for (int i = 2; i < 21; i++) {
            if (x % i != 0) {
                break;
            }
            if (i == 20) {
                cout << x;
                return 0;
            }
        }
        x += 20;
    }
    return 0;
}