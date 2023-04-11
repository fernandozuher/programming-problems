// Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<int> read_an_array(const int SIZE);
vector<int> cut_the_sticks(vector<int> array);
    vector<int> initialize_result(const int SIZE);
    int find_first_element_index_different_of_first_current_shortest_stick_length_index(int index, const vector<int> ARRAY);
    void decrease_sticks_lengths_higher_than_current_shortest_stick_length(int index, vector<int> array, const int SHORTEST_STICK_LENGTH);
void print_array(const vector<int> ARRAY);


int main() {
    const int SIZE {read_a_number()};
    vector<int> array {read_an_array(SIZE)};
    ranges::sort(array);

    const vector<int> RESULT {cut_the_sticks(array)};
    print_array(RESULT);

    return 0;
}

    int read_a_number() {
        int number;
        cin >> number;
        return number;
    }

    vector<int> read_an_array(const int SIZE) {
        vector<int> array(SIZE);
        ranges::generate(array, [](){int number; cin >> number; return number;});
        return array;
    }

    vector<int> cut_the_sticks(vector<int> array) {
        const int SIZE {static_cast<int>(array.size())};
        vector<int> remaining_sticks_of_each_iteration {initialize_result(SIZE)};

        for (int i {0}; i < SIZE; ) {
            const int SHORTEST_STICK_LENGTH {array.at(i)};

            i = {find_first_element_index_different_of_first_current_shortest_stick_length_index(i, array)};
            const int CURRENT_ITERATION_SIZE {SIZE - i};
            if (i == SIZE)
                break;

            remaining_sticks_of_each_iteration.push_back(CURRENT_ITERATION_SIZE);
            decrease_sticks_lengths_higher_than_current_shortest_stick_length(i, array, SHORTEST_STICK_LENGTH);
        }

        return remaining_sticks_of_each_iteration;
    }

        vector<int> initialize_result(const int SIZE) {
            vector<int> remaining_sticks_of_each_iteration {SIZE};
            return remaining_sticks_of_each_iteration;
        }

        int find_first_element_index_different_of_first_current_shortest_stick_length_index(int index, const vector<int> ARRAY) {
            const int SIZE {static_cast<int>(ARRAY.size())};
            const int SHORTEST_STICK_LENGTH {ARRAY.at(index)};
            while (index < SIZE && ARRAY.at(index) == SHORTEST_STICK_LENGTH)
                index++;
            return index;
        }

        void decrease_sticks_lengths_higher_than_current_shortest_stick_length(int index, vector<int> array, const int SHORTEST_STICK_LENGTH) {
            auto lambda_expression = [SHORTEST_STICK_LENGTH](auto& element) {element -= SHORTEST_STICK_LENGTH;};
            for_each(array.begin() + index, array.end(), lambda_expression);
        }

    void print_array(const vector<int> ARRAY) {
        for (auto element : ARRAY)
            cout << element << "\n";
    }
