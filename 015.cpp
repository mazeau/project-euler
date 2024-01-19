//
// Created by Mazeau, Emily on 3/16/23.
// Project Euler Problem 15
//
#include <iostream>
#include <string>

using namespace std;
int main() {
    clock_t start = clock();

    int grid = 19;
    unsigned long long int num = 2;
    for (int i = 1; i < grid+1; i++) {
        num = (2 * (1 + 2 * i) * num) / (1 + i);
        cout << i << " " << num << "\n";
    }

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}