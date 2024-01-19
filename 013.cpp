//
// Created by Mazeau, Emily on 3/15/23.
// Project Euler Problem 13
//
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;
int main() {
    clock_t start = clock();

    unsigned long long int sum = 0;

    ifstream in("input.txt");
    string line;
    while (getline(in,line)) {
        unsigned long long int a = 0;
        string l;
        for (int x = 0; x < 13; x++) {
            a += int(line[x] - '0') * pow(10,12 - x);
        }
        sum += a;
    }

    to_string(sum); // just print the first 10 digits
    for (int x = 0; x < 10; x++) {
        cout << to_string(sum)[x];
    }

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}