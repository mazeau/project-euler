//
// Created by Mazeau, Emily on 3/14/23.
// Project Euler Problem 2
//
#include <iostream>

using namespace std;
int main() {
    int i = 1;
    int j = 2;
    int x;
    int sum = 0;
    while (i + j < 4000000) {
        x = i + j;
        i = j;
        j = x;
        if (j % 2 == 0) {
            sum += x;
        }
    }
    cout << sum + 2;
    return 0;
}