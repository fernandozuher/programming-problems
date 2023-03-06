// Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> read_input();
    vector<int> read_a_number_and_return_it_into_vector();
    vector<int> read_array(const int SIZE);

vector<vector<int>> reduce_input_rotations(vector<vector<int>> input);
vector<vector<int>> rotate_input_array(vector<vector<int>> input);
void print_rotated_array_elements_according_to_queries(vector<vector<int>> input);


int main() {
    vector<vector<int>> input {read_input()};

    input = {reduce_input_rotations(input)};
    input = {rotate_input_array(input)};
    print_rotated_array_elements_according_to_queries(input);

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
            auto read = [](auto& element){cin >> element;};
            ranges::for_each(array, read);
            return array;
        }

    vector<vector<int>> reduce_input_rotations(vector<vector<int>> input) {
        const int ARRAY_SIZE {input.at(1).front()};
        int ROTATION_COUNT {input.at(2).front()};

        if (ARRAY_SIZE > 1)
            input.at(2).front() = {ROTATION_COUNT = ROTATION_COUNT >= ARRAY_SIZE ? ROTATION_COUNT % ARRAY_SIZE : ROTATION_COUNT};
        else
            input.at(2).front() = {ROTATION_COUNT = 0};

        return input;
    }

    vector<vector<int>> rotate_input_array(vector<vector<int>> input) {
        const vector<int> ARRAY {input.front()};
        const int ARRAY_SIZE {input.at(1).front()};
        const int ROTATION_COUNT {input.at(2).front()};

        const auto FIRST_PART_ARRAY_BEGIN_ITERATOR = ARRAY.begin();
        const auto FIRST_PART_ARRAY_END_ITERATOR = ARRAY.begin() + ARRAY_SIZE - ROTATION_COUNT;

        const auto SECOND_PART_ARRAY_BEGIN_ITERATOR = ARRAY.begin() + ARRAY_SIZE - ROTATION_COUNT;
        const auto SECOND_PART_ARRAY_END_ITERATOR = ARRAY.end();

        vector<int> new_array {SECOND_PART_ARRAY_BEGIN_ITERATOR, SECOND_PART_ARRAY_END_ITERATOR};
        const vector<int> SECOND_PART_NEW_ARRAY {FIRST_PART_ARRAY_BEGIN_ITERATOR, FIRST_PART_ARRAY_END_ITERATOR};
        new_array.insert(new_array.end(), SECOND_PART_NEW_ARRAY.begin(), SECOND_PART_NEW_ARRAY.end());

        input.front() = {new_array};
        return input;
    }

    void print_rotated_array_elements_according_to_queries(vector<vector<int>> input) {
        const vector<int> ARRAY {input.front()};
        const vector<int> QUERIES {input.at(3)};

        auto print = [ARRAY](const auto& query){cout << ARRAY.at(query) << "\n";};
        ranges::for_each(QUERIES, print);
    }
