//
// Created by Mazeau, Emily on 6/12/23.
// Project Euler Problem 95
// Current runtime ~8.7s
//

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int sumProperDivisors(int x) {
    int sum = 1;

    for (int i = 2; i < sqrt(x); i++) {
        if (x % i == 0) {
            sum += i + x / i;
        }
    }

    return sum;
}

int main() {
    clock_t start = clock();

    vector<vector<int>> chains;
    int size = 0;

    for (int x = 2; x < 1000001; x++) {
        vector<int> chain;
        chain.push_back(x);
        int n = sumProperDivisors(x);

        while (n < 1000001) {
            if (n == 1) {
                break;
            }
            if (n == chain[0]) {
                if (chain.size() > size) {
                    size = chain.size();
                    chains.push_back(chain);
                    break;
                }
            }
            if (find(chain.begin(), chain.end(), n) != chain.end()) {
                break;
            }
            chain.push_back(n);
            n = sumProperDivisors(n);
        }
    }

    for (const auto& x : chains) {
        if (x.size() == size) {
            size = x.size();
            auto it = min_element(begin(x), end(x));
            cout << *it << endl;
        }
    }

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}