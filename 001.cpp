//
// Created by Mazeau, Emily on 3/14/23.
// Project Euler Problem 1
//
#include <iostream>

using namespace std;
int main() {
    int x = 0;
    int i = 0;
    while (i < 1000) {
        if (i % 3 == 0) {
            x += i;
        }
        else if (i % 5 == 0) {
            x += i;
        }
        i++;
    }
    cout << x;
    return 0;
}
