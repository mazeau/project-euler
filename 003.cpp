//
// Created by Mazeau, Emily on 3/14/23.
// Project Euler Problem 3 - BROKEN
//
#include <iostream>
#include <cmath>

using namespace std;
int main() {
    long num = 600851475143;
    int lpf;
    int i = 2;
    bool prime = true;
    while (i < sqrt(num)) {
        if (num % i == 0) {
            int j = 2;
            while (j < sqrt(i)) {
                if (num % j == 0) {
                    prime = false;
                    cout << "Not prime " << i << "\n";
                    break;
                }
                j++;
            }
            if (prime == true) {
                lpf = i;
            }
            cout << i << "\n";
        }
        i++;
    }
    cout << lpf;
    return 0;
}
