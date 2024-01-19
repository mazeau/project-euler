//
// Created by Mazeau, Emily on 5/9/23.
// Project Euler Problem 32
//

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

set<int> check_products(string s) {
    set<int> prods;

    for (int x = 1; x < 5; x++) {
        for (int y = 1; y < 5; y++) {
            string p1 = s.substr(0, x);
            string p2 = s.substr(x, y);
            string prod = s.substr(x+y, 9-(x+y));

            if (stoi(p1) * stoi(p2) == stoi(prod)) {
                prods.insert(stoi(prod));
            }
        }
    }

    return prods;
}

int main() {
    clock_t start = clock();

    string s = "123456789";

    set<int> product;

    do {
        set<int> p = check_products(s);
        product.insert(p.begin(), p.end());
    }
    while (next_permutation(s.begin(), s.end()));

    int sum = accumulate(product.rbegin(), product.rend(), 0);

    cout << sum << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}