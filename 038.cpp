//
// Created by Mazeau, Emily on 5/9/23.
// Project Euler Problem 38
//

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

bool hasMultiples(string s) {
    for (int x = 1; x < 5; x++) {
        string p1 = s.substr(0, x);
        int i = stoi(p1);

        string s2 = p1;
        int j = 2;
        while (s2.length() < s.length()) {
            s2 += to_string(i * j);
            j++;
        }
        if (s2 == s) {
            return true;
        }
    }
    return false;
}

int main() {
    clock_t start = clock();

    string s = "987654321";

    do {
        if (hasMultiples(s)){
            cout << s << endl;
            break;
        }
    }
    while (prev_permutation(s.begin(), s.end()));

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}