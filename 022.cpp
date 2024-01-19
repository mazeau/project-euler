//
// Created by Mazeau, Emily on 3/22/23.
// Project Euler Problem 22
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int getNameScore(string s) {
    int score = 0;
    for (int i = 0; i < s.length(); i++) {
        score += int(s[i]) - 64;
    }
    return score;
}

int main() {
    clock_t start = clock();

    int sum = 0;
    vector<string> names;
    ifstream in("/Users/emz/Code/ProjectEuler/p022_names.txt");
    string line;
    while (getline(in,line,',')) {
        // remove quotes from start and end
        line.erase(0,1);
        line.pop_back();
        names.push_back(line);
    }

    std::sort(names.begin(), names.end());

    for (int i = 0; i < int(names.size()); i++) {
        sum += getNameScore(names[i]) * (i + 1);
    }
    cout << sum << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}