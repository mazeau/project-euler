//
// Created by Mazeau, Emily on 5/18/23.
// Project Euler Problem 35
//

#include <iostream>
#include <cmath>
#include <string>
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

    set<int> primes;

    for (int x=2; x < 1000000; x++) {
        if (isPrime(x)) {
            primes.insert(x);
        }
    }

    set<int> circular_primes;

    for (auto f : primes) {
        if (circular_primes.contains(f)) {
            continue;
        }
        string s = to_string(f);
        set<int> temp;
        bool all_primes = true;

        int x = 0;
        while (x < s.length()) {
            int s_int = stoi(s);
            temp.insert(s_int);
            if (!primes.contains(s_int)) {
                all_primes = false;
                break;
            }
            rotate(s.begin(), s.begin() + 1, s.end());
            x++;
        }

        if (all_primes) {
            circular_primes.insert(temp.begin(), temp.end());
        }
    }

    cout << circular_primes.size() << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}