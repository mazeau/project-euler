//
// Created by Mazeau, Emily on 6/15/23.
// Project Euler Problem 50
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>
#include <numeric>

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

    vector<int> primes;

    for (int x=2; x<10000; x++) {
        if (isPrime(x)) {
            primes.push_back(x);
        }
    }

    for (int i=primes.size()-1; i>5; i--) {
        for (int j=primes.size()-i; j>-1; j--) {
            int sum = accumulate(primes.begin() + j, primes.begin() + i + j, 0);
            if (sum < 1000000) {
                if (isPrime(sum)) {
                    cout << sum  << "  " << i << endl;
                    break;
                }
            }
        }
    }

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}