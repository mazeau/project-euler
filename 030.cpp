//
// Created by Mazeau, Emily on 4/21/23.
// Project Euler Problem 30
//

#include <iostream>
#include <cmath>
#include <string>
#include <iterator>

using namespace std;

int main() {
    clock_t start = clock();

    int nums = 0;

    for (int i = 2; i < 999999; i++) {
        string str_i = to_string(i);
        int sum = 0;
        for (int j = 0; j < str_i.length(); j++) {
            int x = str_i[j] - '0';
            sum += pow(x, 5);
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
