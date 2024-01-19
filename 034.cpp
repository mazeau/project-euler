//
// Created by Mazeau, Emily on 4/21/23.
// Project Euler Problem 34
//

#include <iostream>
#include <string>
#include <iterator>

using namespace std;

int factorial(int x) {
    if (x == 0) {
        return 1;
    }
    for (int i = x - 1; i > 1; i--) {
        x *= i;
    }
    return x;
}

int main() {
    clock_t start = clock();

    int nums = 0;

    for (int i = 3; i < 1999999; i++) {
        string str_i = to_string(i);
        int sum = 0;
        for (int j = 0; j < str_i.length(); j++) {
            int x = str_i[j] - '0';
            sum += factorial(x);
        }
        if (sum == i) {
            nums += sum;
        }
    }

    cout << nums << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}