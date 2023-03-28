// Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

#include "Sequence_Equation.h"

using namespace std;

int read_a_number();
vector<int> read_an_array(const int SIZE);


int main() {
    const int SIZE {read_a_number()};
    const vector<int> ARRAY {read_an_array(SIZE)};

    const Sequence_Equation obj(ARRAY);
    obj.print_permutated_array();

    return 0;
}

    int read_a_number() {
        int number;
        cin >> number;
        return number;
    }

    vector<int> read_an_array(const int SIZE) {
        vector<int> array(SIZE);
        auto read = []() {int element; cin >> element; return element;};
        ranges::generate(array, read);
        return array;
    }
