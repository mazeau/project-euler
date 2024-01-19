//
// Created by Mazeau, Emily on 5/27/23.
// Project Euler Problem 61
//

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

bool checkWholeNumber(auto x) {
    if (x == round(x)) {
        return true;
    }
    return false;
}

auto trigonal(double x) {
    auto p = x * (x+1) / 2.;
    return p;
}

auto square(double x) {
    auto p = x * x;
    return p;
}

auto pentagonal(double x) {
    auto p = x * (3 * x - 1) / 2.;
    return p;
}

auto hexagonal(double x) {
    auto p = x * (2 * x - 1);
    return p;
}

auto heptagonal(double x) {
    auto p = x * (5 * x - 3) / 2.;
    return p;
}

auto octagonal(double x) {
    auto p = x * (3 * x - 2);
    return p;
}

bool checkFourDigit(double x) {
    if (x < 10000 && x > 999) {
        return true;
    }
    return false;
}

int getLastTwoDigits(int x) {
    auto n = x / 100.;
    n = floor(n);
    return x - (n * 100);
}

int getFirstTwoDigits(int x) {
    auto n = x / 100.;
    return floor(n);
}

int main() {
    clock_t start = clock();

    vector<int> tri;
    vector<int> squ;
    vector<int> pent;
    vector<int> hex;
    vector<int> hept;
    vector<int> oct;

    vector<vector<int>> nums;

    int x = 10;
    while (x) {
        if (checkFourDigit(trigonal(x))) {
            tri.push_back(trigonal(x));
        }
        if (checkFourDigit(square(x))) {
            squ.push_back(square(x));
        }
        if (checkFourDigit(pentagonal(x))) {
            pent.push_back(pentagonal(x));
        }
        if (checkFourDigit(hexagonal(x))) {
            hex.push_back(hexagonal(x));
        }
        if (checkFourDigit(heptagonal(x))) {
            hept.push_back(heptagonal(x));
        }
        if (checkFourDigit(octagonal(x))) {
            oct.push_back(octagonal(x));
        }

        if (trigonal(x) > 10000) {
            break;
        }
        x++;
    }

    nums = {
            {tri},
            {squ},
            {pent},
            {hex},
            {hept},
            {oct},
    };

    do {
        for (auto f: nums[0]) {
            for (int i=0; i<nums[1].size(); i++) {
                if (getFirstTwoDigits(nums[1][i]) == getLastTwoDigits(f)) {
                    for (int j=0; j<nums[2].size(); j++) {
                        if (getFirstTwoDigits(nums[2][j]) == getLastTwoDigits(nums[1][i])) {
                            for (int k=0; k<nums[3].size(); k++) {
                                if (getFirstTwoDigits(nums[3][k]) == getLastTwoDigits(nums[2][j])) {
                                    for (int l=0; l<nums[4].size(); l++) {
                                        if (getFirstTwoDigits(nums[4][l]) == getLastTwoDigits(nums[3][k])) {
                                            for (int m=0; m<nums[5].size(); m++) {
                                                if (getFirstTwoDigits(nums[5][m]) == getLastTwoDigits(nums[4][l])) {
                                                    if (getLastTwoDigits(nums[5][m]) == getFirstTwoDigits(f)) {
                                                        cout << f+nums[1][i]+nums[2][j]+nums[3][k]+nums[4][l]+nums[5][m] << endl;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    while (next_permutation(nums.begin(), nums.end()));

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}