//
// Created by Mazeau, Emily on 3/15/23.
// Project Euler Problem 7
//
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(unsigned long int x) {
    if (x == 2) {
        return true;
    }
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int count = 0;
    int i = 2;

    while (count < 10001) {
        if (isPrime(i)) {
            count += 1;
        }
        i++;
    }
    cout << count << "\n" << i -1;
    return 0;
}