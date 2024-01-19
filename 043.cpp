//
// Created by Mazeau, Emily on 5/18/23.
// Project Euler Problem 43
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
#include <iterator>
#include <regex>
#include <map>

using namespace std;

string sumStrings(string x, string y) {
    bool carry = false;
    string s;

    if (y.length() > x.length()) {
        x.insert(0, int(y.length() - x.length()), '0');
    }
    if (x.length() > y.length()) {
        y.insert(0, int(x.length() - y.length()), '0');
    }

    for (int i = int(x.length()) - 1; i >= 0; i--) {
        int digit;

        int num = x[i] - '0';
        num = (y[i] - '0') + num;
        if (carry) {
            num++;
        }

        if (num > 9) {
            if (i == 0) {
                s = to_string(num) + s;
                break;
            }
            digit = num - 10;
            carry = true;
        }
        else {
            digit = num;
            carry = false;
        }

        s = to_string(digit) + s;
    }
    return s;
}


int main() {
    clock_t start = clock();

    string s = "0123456789";
    string sum = "0";
    map<int, int> divisors = {
            {1, 2},
            {2, 3},
            {3, 5},
            {4, 7},
            {5, 11},
            {6, 13},
            {7, 17},
    };

    do {
        bool div = true;
        for (int x=1; x < 8; x++) {
            string small_s = s.substr(x, 3);
            int s_int = stoi(small_s);

            if (s_int % divisors[x] != 0) {
                div = false;
                break;
            }
        }

        if (div) {
            sum = sumStrings(sum, s);
        }
    }
    while (next_permutation(s.begin(), s.end()));

    cout << sum << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}