//
// Created by Mazeau, Emily on 5/9/23.
// Project Euler Problem 41
//

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

bool isPrime(unsigned long int x) {
    if (x == 2) {
        return true;
    }
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

bool generate_pandigitals(string s) {
    do {
        int s_int = stoi(s);
        if (isPrime(s_int)) {
            cout << s << endl;
            return true;
        }
    }
    while (prev_permutation(s.begin(), s.end()));
}

int main() {
    clock_t start = clock();
    string s = "987654321";

    while (!generate_pandigitals(s)) {
        s.erase(0, 1);
    }

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}