//
// Created by Mazeau, Emily on 3/14/23.
// Project Euler Problem 6
//
#include <iostream>
#include <cmath>

using namespace std;
int main() {
    double sqsum = 0;
    double sumsq = 0;

    for (double i = 1; i < 101; i++) {
        sumsq += pow(i, 2);
        sqsum += i;
    }
    sqsum = pow(sqsum, 2);
    printf("%.17g", sqsum - sumsq);
//    cout << sqsum - sumsq;
    return 0;
}
