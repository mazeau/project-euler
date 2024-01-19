//
// Created by Mazeau, Emily on 5/9/23.
// Project Euler Problem 42
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

bool is_triangle(int n) {
    double number = (std::sqrt(8 * n + 1) - 1) * 0.5;
    double int_part;
    if (modf(number, &int_part) == 0) {
        return true;
    }
    return false;
}

int main() {
    clock_t start = clock();

    vector<string> words;
    ifstream in("/Users/emz/Code/ProjectEuler/p042_words.txt");
    string line;
    while (getline(in,line,',')) {
        // remove quotes from start and end
        line.erase(0,1);
        line.pop_back();
        words.push_back(line);
    }

    int count = 0;

    for (auto i: words) {
        int word_sum = 0;
        for (char& c : i) {
            int int_c = c - '0' - 16;
            word_sum += int_c;
        }
        if (is_triangle(word_sum)) {
            count++;
        }
    }

    cout << count << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}