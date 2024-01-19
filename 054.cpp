//
// Created by Mazeau, Emily on 5/8/23.
// Project Euler Problem 54
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;

map<char, int> card_ranks = {
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'T', 10},
        {'J', 11},
        {'Q', 12},
        {'K', 13},
        {'A', 14}
};

set<string> getCards(string s) {
    set <string> hand = {};
    for (int i = 0; i < int(s.length()); i += 3) {
        hand.insert(s.substr(i, 2));
    }
    return hand;
}

bool checkFlush(const set<string>& hand) {
    char suits;
    for (auto f : hand) {
        if (suits) {
            if (f[1] != suits) {
                return false;
            };
        }
        suits = f[1];
    }
    return true;
}

bool checkStraight(const set<string>& hand) {
    vector<int> cards;
    for (auto f : hand) {
        int rank = card_ranks[f[0]];
        if (!cards.empty()) {
            if (abs(cards.at(0) - rank) > 4) {
                return false;
            }
            for (auto i : cards) {
                if (i == rank) {
                    return false;
                }
            }
        }
        cards.push_back(rank);
    }
    sort(cards.begin(), cards.end());
    int lowest_card = cards.at(0);

    for (auto f: cards) {
        if (f != lowest_card) {
            return false;
        }
        lowest_card++;
    }
    return true;
}

double checkPairs(const set<string>& hand) {
    vector<int> cards;
    for (auto f : hand) {
        cards.push_back(card_ranks[f[0]]);
    }
    sort(cards.begin(), cards.end());

    map<int, int> duplicate;

    auto beg = begin(cards) + 1;
    for (;beg != end(cards); ++beg) {
        if (*beg == *(beg - 1)) {
            duplicate[*beg]++;
        }
    }

    if (duplicate.size() == 0) {
        return 1 + cards.back() * 0.01;  // no pairs
    }
    if (duplicate.size() == 1) {
        if (duplicate.rbegin()->second == 2) {
            return 4 + duplicate.rbegin()->first * 0.01;
        }
        if (duplicate.rbegin()->second == 3) {
            return 8 + duplicate.rbegin()->first * 0.01;
        }
        return 2 + duplicate.rbegin()->first * 0.01;
    }
    if (duplicate.size() == 2) {
        if (duplicate.rend()->second == 2 || duplicate.rbegin()->second == 2) {
            return 7 + duplicate.rend()->first * 0.01;
        }
        return 3 + duplicate.rend()->first * 0.01;
    }
}

double checkHand(const set<string>& hand) {
    vector<int> cards;
    for (auto f : hand) {
        cards.push_back(card_ranks[f[0]]);
    }
    sort(cards.begin(), cards.end());

    bool is_flush = checkStraight(hand);
    bool is_straight = checkStraight(hand);

    if (is_flush) {
        if (is_straight) {
            if (cards.back() = 14) {
                return 10;
            }
            return 9 + cards.back() * .01;
        }
        return 6 + cards.back() * .01;
    }
    if (is_straight) {
        return 5 + cards.back() * .01;
    }

    return checkPairs(hand);
}


int main() {
    clock_t start = clock();

    ifstream in("/Users/emz/Code/ProjectEuler/p054_poker.txt");
    string line;
    int wins = 0;

    while (getline(in,line)) {
        set<string> h1 = getCards(line.substr(0, 14));
        set<string> h2 = getCards(line.substr(15,-1));

        double p1 = checkHand(h1);
        double p2 = checkHand(h2);

        if (checkHand(h1) > checkHand(h2)) {
            wins++;
        }
    }

    cout << wins << endl;

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}