//
// Created by Mazeau, Emily on 4/21/23.
// Project Euler Problem 26
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int division(int x) {
    int i = 10;
    string s = "";
    vector<int> remainders;

    while (i != 0) {
        while (x > i) {
            i *= 10;
            s += "0";
        }

        int d = i / x;
        s += to_string(d);
        i = (i % x) * 10;

        if (s.length() > 1) {
            auto it = find(remainders.begin(), remainders.end(), i);
            if (it != remainders.end()) {
                int index = distance(remainders.begin(), it);
                return remainders.size() - index;
            }
        }
        remainders.push_back(i);
    }
    return 0;
}

int main() {
    clock_t start = clock();

    int repeats;
    int d = 0;

    for (int i = 2; i < 1000; i++) {
        int j = division(i);

        if (j > repeats) {
            repeats = j;
            d = i;
        }
    }

    cout << d << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}
