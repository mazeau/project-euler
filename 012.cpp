//
// Created by Mazeau, Emily on 3/15/23.
// Project Euler Problem 12
//
#include <iostream>
#include <cmath>

using namespace std;

int numFactors(int x) {
    int count = 0;

    for (int i = 1; i < sqrt(x); i++) {
        if (x % i == 0) {
            count++;
        }
    }
    return count * 2;
}
int main() {
    clock_t start = clock();

    int i = 1;
    int tri = 0;

    while (i) {
        tri += i;
        if (numFactors(tri) >= 500) {
            cout << tri;
            clock_t stop = clock();
            double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
            printf("\nTime elapsed: %.5f\n", elapsed);
            return 0;
        }
        i++;
    }
    return 0;
}
