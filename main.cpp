#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <regex>
#include <vector>

using namespace std;

int main() {
    clock_t start = clock();
    

    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
    return 0;
}