//
// Created by Mazeau, Emily on 4/21/23.
// Project Euler Problem 28
//

#include <iostream>
#include <iterator>

using namespace std;

int main() {
    clock_t start = clock();
    int i = 1;
    int count = 1;
    int sum = 0;

    while (i < 1002001) {
        for (int j = 0; j < 4; j++) {
            sum += i;
            i += 2 * count;
        }
        count ++;
    }
    cout.precision(17);
    cout << sum + 1001*1001 << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}
