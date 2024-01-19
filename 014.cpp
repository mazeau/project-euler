//
// Created by Mazeau, Emily on 3/16/23.
// Project Euler Problem 14
//
#include <iostream>
#include <string>

using namespace std;

bool isEven(unsigned long long int x) {
    if (x % 2 == 0) {
        return true;
    }
    return false;
}

unsigned long long int findNext(unsigned long long int x) {
    if (isEven(x)) {
        return x / 2;
    }
    return 3 * x + 1;
}

int main() {
    clock_t start = clock();

    int num = 0;
    int longestchain = 0;
    int x = 1;

    while (x < 1000001) {
        unsigned long long int chain = 1;
        unsigned long long int n = x;

        while (n != 1) {
            n = findNext(n);
            chain++;
        }

        if (chain > longestchain) {
            longestchain = chain;
            num = x;
        }
        x++;
    }

    cout << num;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}