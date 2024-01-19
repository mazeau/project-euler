//
// Created by Mazeau, Emily on 3/20/23.
//
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

string sumStrings(string x, string y) {
    bool carry = false;
    string s;

    if (y.length() > x.length()) {
        x.insert(0, int(y.length() - x.length()), '0');
    }

    for (int i = int(x.length()) - 1; i >= 0; i--) {
        int digit;

        int num = x[i] - '0';
        num = (y[i] - '0') + num;
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

    string s1 = "1";
    string s2 = "2";
    int count = 2;
    string sx;

    while (int(s1.length()) < 1000) {
        sx = sumStrings(s1, s2);
        s1 = s2;
        s2 = sx;
        count++;
    }

    cout << count << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}