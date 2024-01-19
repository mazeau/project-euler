//
// Created by Mazeau, Emily on 3/20/23.
// Project Euler Problem 21
//
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int sumProperDivisors(int x) {
    int sum = 1;

    for (int i = 2; i < sqrt(x); i++) {
        if (x % i == 0) {
            sum += i + x / i;
        }
    }

    return sum;
}

bool isAmicable(int x) {
    int sum = sumProperDivisors(x);
    if (sum == x) {
        return false;
    }
    if (sumProperDivisors(sum) == x) {
        return true;
    }
    return false;
}

int main() {
    clock_t start = clock();
    int sum = 0;

    for (int i = 2; i < 10000; i++) {
        if (isAmicable(i)) {
            cout << i << "\n";
            sum += i;
        }
    }

    cout << sum;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}