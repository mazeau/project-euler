//
// Created by Mazeau, Emily on 4/20/23.
// Project Euler Problem 18 & 67
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int toInt(string s) {
    int x = stoi(s);
    return x;
}

int main() {
    clock_t start = clock();

    vector<vector<int>> nums;
    vector<int> row_max;

    ifstream in("/Users/emz/Code/ProjectEuler/p067_triangle.txt");
    string line;
    string s;
    while (getline(in,line)) {
        vector<int> n;
        for (int i = 0; i < int(line.length()); i+=3) {
            s = line[i];
            s += line[i+1];
            int x = toInt(s);
            n.push_back(x);
        }
        nums.push_back(n);
    }

    for (int i = nums.size() - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            nums[i][j] += max(nums[i+1][j], nums[i+1][j+1]);
        }
    }
    cout << nums[0][0] << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}