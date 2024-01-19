//
// Created by Mazeau, Emily on 5/22/23.
// Project Euler Problem 44
//

#include <iostream>
#include <cmath>
#include <iterator>

using namespace std;

auto pentagonal(double x) {
    auto p = x * (3*x-1) / 2.;
    return p;
}

bool checkPentagonal(int x) {
    double n = (sqrt(24*x+1)+1)/6;
    if (n == round(n)) {
        return true;
    }
    return false;
}

int main() {
    clock_t start = clock();

    double difference = 99999999999;

    for (int i=2; i<9999; i++) {
        for (int j=1; j<i; j++) {
            double sum = pentagonal(i) + pentagonal(i-j);
            double dif = pentagonal(i) - pentagonal(i-j);
            if (checkPentagonal(sum) && checkPentagonal(dif)) {
                if (dif < difference){
                    difference = dif;
                }
            }
        }
    }

    cout.precision(17);
    cout << difference << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}