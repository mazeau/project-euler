//
// Created by Mazeau, Emily on 3/20/23.
// Projeect Euler Problem 23
//
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <limits>
#include <regex>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

bool isAbundant(int x) {
    int sum = 1;

    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            sum += i + x / i;
        }
        if (i * i == x) {
            sum -= i;
        }
    }

    if (sum > x) {
        return true;
    }
    return false;
}

int main() {
    clock_t start = clock();

    int sum = 0;
    vector<int> v = {};

    for (int i = 12; i <28123; i++) {
        if (isAbundant(i)) {
            v.push_back(i);
        }
    }

    while (*max_element(v.begin(), v.end()) + *min_element(
            v.begin(), v.end()) > 28123) {
        v.pop_back();
    }

    // find all sums of abundants
    set<int> s;
    for (size_t i = 0; i < v.size(); i++) {
        if (2 * v[i] < 28123) {
            s.insert(2 * v[i]);
        }

        int j = 0;
        while (j < i) {
            if (v[i] + v[j] > 28123) {
                break;
            }
            s.insert(v[i] + v[j]);
            j++;
        }
    }

    set<int> n;
    for (int i = 1; i < 28123; i++) {
        n.insert(i);
    }
    set<int> s_int;
    set_difference(n.begin(), n.end(), s.begin(), s.end(),
                   inserter(s_int, s_int.end()));

    for (const int& i : s_int) {
        sum += i;
    }

    cout << "\n" << sum << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}