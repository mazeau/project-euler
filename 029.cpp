//
// Created by Mazeau, Emily on 4/21/23.
// Project Euler Problem 29
//

#include <iostream>
#include <string>
#include <set>
#include <iterator>

using namespace std;

string multStrings(string x, string y) {
    string s;

    for (int j = int(y.length()) - 1; j >= 0; j--) {
        int y_int = y[j] - '0';
        int carry = 0;
        string sx;

        for (int i = int(x.length()) - 1; i >= 0; i--) {  // start at last digit of x
            int digit;
            int x_int = x[i] - '0';

            x_int = y_int * x_int;
            x_int += carry;
            string x_str = to_string(x_int);

            if (x_int > 9) {
                if (i == 0) {  // leftmost number, no carry
                    sx = to_string(x_int) + sx;
                    break;
                }
                digit = x_str[1] - '0';
                carry = x_str[0] - '0';
            }
            else {
                digit = x_int;
                carry = 0;
            }

            sx = to_string(digit) + sx;
        }

        if (j != int(y.length()) - 1) {
            sx = sx + string(int(y.length()) - 1 - j, '0');
        }

        // making the same size before adding
        if (int(sx.length()) > int(s.length())) {
            s.insert(0, int(sx.length()) - int(s.length()), '0');
        }
        if (int(sx.length()) < int(s.length())) {
            sx.insert(0, int(s.length()) - int(sx.length()), '0');
        }

        // add the strings together
        bool plus_one = false;
        for (int i = int(s.length()) - 1; i >= 0; i--) {
            int digit;
            int n1 = s[i] - '0';
            int n2 = sx[i] - '0';
            digit = n1 + n2;
            if (plus_one) {
                digit++;
            }

            if (digit > 9) {
                if (i == 0) {
                    s.insert(0, 1, '1');
                    digit -= 10;
                    s[1] = u_char(digit + '0');
                    break;
                }
                digit -= 10;
                plus_one = true;
            }
            else {
                plus_one = false;
            }

            s[i] = u_char(digit + '0');
        }
    }
    return s;
}

int main() {
    clock_t start = clock();

    set<string> nums;

    for (int i = 2; i < 101; i++) {
        string s = multStrings(to_string(i), to_string(i));
        nums.insert(s);
        for (int j = 3; j < 101; j++) {
            s = multStrings(s, to_string(i));
            nums.insert(s);
        }
    }

    cout << nums.size() << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}
