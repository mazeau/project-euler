//
// Created by Mazeau, Emily on 6/12/23.
// Project Euler Problem 49
//

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
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

int main() {
    clock_t start = clock();

    for (int x = 1487; x < 10000; x++) {
        vector<int> prime_perms;
        string x_str = to_string(x);

        do {
            if (stoi(x_str) > 999) {
                if (isPrime(stoi(x_str))) {
                    prime_perms.push_back(stoi(x_str));
                }
            }
        }
        while (next_permutation(x_str.begin(), x_str.end()));

        if (prime_perms.size() > 2) {
            for (int i = 0; i < prime_perms.size(); i++) {
                for (int j = i + 1; j < prime_perms.size(); j++) {
                    int tmp = prime_perms[j] - prime_perms[i];

                    if (find(prime_perms.begin(), prime_perms.end(), tmp+prime_perms[i]) != prime_perms.end()) {
                        if (find(prime_perms.begin(), prime_perms.end(), tmp*2+prime_perms[i]) != prime_perms.end()) {
                            cout << prime_perms[i] << prime_perms[i]+tmp << prime_perms[i]+2*tmp << endl;
                            break;
                        }
                    }

                }
            }
        }
    }

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}