//
// Created by Mazeau, Emily on 3/16/23.
//
#include <iostream>
#include <string>

using namespace std;

int sumString(string x) {
    int sum = 0;
    for (int i = 0; i < x.length(); i++) {
        int num = x[i] - '0';
        sum += num;
    }
    return sum;
}

string doubleNum(string x) {
    bool carry = false;
    string s;

    for (int i = int(x.length()) - 1; i >= 0; i--) {
        int digit;

        int num = x[i] - '0';
        num = 2 * num;
        if (carry) {
            num++;
        }

        if (num > 9) {
            if (i == 0) {
                s = to_string(num) + s;
                break;
            }
            digit = num - 10;
            carry = true;
        }
        else {
            digit = num;
            carry = false;
        }

        s = to_string(digit) + s;
    }
    return s;
}

int main() {
    clock_t start = clock();

    string s = "2";

    for (int j = 1; j < 1000; j++) {
        s = doubleNum(s);
    }

    cout << s << "\n";
    cout << sumString(s);

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}