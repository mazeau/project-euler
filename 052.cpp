//
// Created by Mazeau, Emily on 6/15/23.
// Project Euler Problem 52
//

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

bool sameDigits(int x) {
    string x_str = to_string(x);

    int count = 0;
    for (int i=2; i<7; i++) {
        string str = to_string(x*i);
        do {
            if (str == x_str) {
                count++;
                break;
            }
        }
        while (next_permutation(x_str.begin(), x_str.end()));
        if (count == 0) {
            break;
        }
    }

    if (count == 5) {
        return true;
    }
}

int main() {
    clock_t start = clock();

    int x = 100;

    while (x) {
        if (sameDigits(x)) {
            cout << x << endl;
            break;
        }
        x++;
    }

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}