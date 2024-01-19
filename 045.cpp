//
// Created by Mazeau, Emily on 5/22/23.
// Project Euler Problem 45
//

#include <iostream>
#include <cmath>
#include <iterator>

using namespace std;

auto trigonal(double x) {
    auto p = x * (x+1) / 2.;
    return p;
}

bool checkPentagonal(double x) {
    double n = (sqrt(24*x+1)+1)/6;
    if (n == round(n)) {
        return true;
    }
    return false;
}

bool checkHexagonal(double x) {
    double n = (sqrt(8*x+1)+1)/4;
    if (n == round(n)) {
        return true;
    }
    return false;
}

int main() {
    clock_t start = clock();
    double i = 286;

    while (i) {
        if (checkPentagonal(trigonal(i)) && checkHexagonal(trigonal(i))) {
            cout.precision(17);
            cout << trigonal(i) << endl;
            break;
        }
        i++;
    }

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}