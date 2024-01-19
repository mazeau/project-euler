//
// Created by Mazeau, Emily on 5/8/23.
// Project Euler Problem 40
//

#include <iostream>
#include <string>
#include <iterator>

using namespace std;

int main() {
    clock_t start = clock();

    string s = "";

    for (int x = 0; x < 1000000; x++) {
        s += to_string(x);
    }

    int sum = s[1] - '0';
    for (int x = 10; x < 1000000; x*=10) {
        sum *= s[x] - '0';
    }

    cout << sum << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}