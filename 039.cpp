//
// Created by Mazeau, Emily on 4/25/23.
// Project Euler Problem 39
//

#include <iostream>
#include <cmath>
#include <iterator>

using namespace std;

double getSides(int p) {
    double solutions = 0;

    for (int a=1; a < p/3; a++) {
        int b = (pow(p, 2) / 2 - a*p);
        if (b % (p-a) == 0) {
            solutions++;
        }
    }
    return solutions;
}

int main() {
    clock_t start = clock();

    int nums = 0, p;

    for (int i=1; i <1001; i++) {
        int n = getSides(i);
        if (n > nums) {
            nums = n;
            p = i;
        }
    }

    cout << p << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}