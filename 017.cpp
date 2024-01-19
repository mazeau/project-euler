//
// Created by Mazeau, Emily on 3/16/23.
// Project Euler Problem 17
//
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int singlesCount(int x) {
    if (x == 1 || x == 2 || x == 6) {
        return 3;
    }
    if (x == 4 || x == 5 || x == 9) {
        return 4;
    }
    if (x == 3 || x == 7 || x == 8) {
        return 5;
    }
    if (x == 0) {
        return 0;
    }
}

int letterCount(int x) {
    int len = 0;
    string s = to_string(x);

    if (x == 1000) {
        return 11;
    }
    if (x < 10) {
        return singlesCount(x);
    }

    if (x >= 100) {
        if (x % 100 == 0) {
            len += 7;  // hundred
        }
        else {
            len += 10;  // hundred and
        }
        len += singlesCount(int(s[0] - '0'));
        x = x - 100 * floor(x/100);
        s = to_string(x);
    }

    if (x >= 20) {
        if (int(s[0] - '0') == 4 || int(s[0] - '0') == 5 || int(s[0] - '0') == 6) {
            len += 5;
            len += singlesCount(int(s[1] - '0'));
        }
        if (int(s[0] - '0') == 2 || int(s[0] - '0') == 3 || int(s[0] - '0') == 8 || int(s[0] - '0') == 9) {
            len += 6;
            len += singlesCount(int(s[1] - '0'));
        }
        if (int(s[0] - '0') == 7) {
            len += 7;
            len += singlesCount(int(s[1] - '0'));
        }
    }

    if (x < 10) {
        len += singlesCount(x);
        return len;
    }
    if (x == 10) {
        len += 3;
        return len;
    }
    if (x == 11 || x == 12) {
        len += 6;
        return len;
    }
    if (x == 13 || x == 18) {
        len += 8;
        return len;
    }
    if (x == 15) {
        len += 7;
        return len;
    }
    if (x == 14 || x == 16 || x == 17 || x == 19) {
        len += 4;  // teen
        len += singlesCount(int(s[1]) - '0');
        return len;
    }
    return len;
}

int main() {
    clock_t start = clock();
    int sum = 0;

    for (int x = 1; x < 1001; x++) {
        sum += letterCount(x);
    }
    cout << sum << "\n";

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}