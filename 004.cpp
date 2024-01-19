//
// Created by Mazeau, Emily on 3/14/23.
// Project Euler Problem 4
//
#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int x = 997; // 997799

    while (x > 100) {
        string n = to_string(x);
        string m(n.rbegin(), n.rend());
        n += m;
        int num = stoi(n);

        int i = sqrt(num);
        while (i > 100) {
            if (num % i == 0) {
                if (num / i > 999) {
                    break;
                }
                cout << num;
                return 0;
            }
            i--;
        }
        x--;
    }
    return -1;
}