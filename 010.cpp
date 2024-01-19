//
// Created by Mazeau, Emily on 3/15/23.
// Project Euler Problem 10
//
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(unsigned long int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    clock_t start = clock();
    unsigned long int sum = 0;

    for (int i = 2; i < 2000000; i++) {
        if (isPrime(i)) {
            sum += i;
        };
    }
    cout << sum;
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}