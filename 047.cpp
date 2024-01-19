//
// Created by Mazeau, Emily on 6/12/23.
// Project Euler Problem 47
//

#include <iostream>
#include <cmath>
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

set<int> primeFactors(int x) {
    set<int> factors;
    int i = 2;
    while (x > 2) {
        if (isPrime(x)) {
            factors.insert(x);
            return factors;
        }
        if (x % i == 0) {
            if (isPrime(i)) {
                factors.insert(i);
                x = x / i;
                i = 2;
                continue;
            }
        }
        if (i > x) {
            set<int> t;
            return t;
        }
        i++;
    }
    return factors;
}

int main() {
    clock_t start = clock();

    int num_distinct_primes = 4;

    for (int i = 644; i < 2000000; i++) {
        vector<int> factors;
        for (int j = 0; j < num_distinct_primes; j++) {
            set<int> f = primeFactors(i+j);
            if (f.size() != num_distinct_primes) {
                break;
            }
            copy(f.begin(), f.end(), back_inserter(factors));
        }
        if (factors.size() == num_distinct_primes * num_distinct_primes) {
            cout << i << endl;
            break;
        }
    }

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}