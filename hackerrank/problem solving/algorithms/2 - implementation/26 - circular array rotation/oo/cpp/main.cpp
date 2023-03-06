// Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

#include "circular_array_rotation.h"

using namespace std;

vector<vector<int>> read_input();
    vector<int> read_a_number_and_return_it_into_vector();
    vector<int> read_array(const int SIZE);


int main() {
    const vector<vector<int>> INPUT {read_input()};
    Circular_Array_Rotation obj(INPUT);

    return 0;
}

    vector<vector<int>> read_input() {
        vector<int> array_size {read_a_number_and_return_it_into_vector()};
        vector<int> rotation_count {read_a_number_and_return_it_into_vector()};
        vector<int> queries_size {read_a_number_and_return_it_into_vector()};

        vector<int> array {read_array(array_size.front())};
        vector<int> queries {read_array(queries_size.front())};

        vector<vector<int>> input(5);
        input.at(0) = {array};
        input.at(1) = {array_size};
        input.at(2) = {rotation_count};
        input.at(3) = {queries};
        input.at(4) = {queries_size};

        return input;
    }

        vector<int> read_a_number_and_return_it_into_vector() {
            vector<int> number(1);
            cin >> number.at(0);
            return number;
        }

        vector<int> read_array(const int SIZE) {
            vector<int> array(SIZE);
            auto read = [](auto& element) {cin >> element;};
            ranges::for_each(array, read);
            return array;
        }
