// Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
vector<int> read_an_array(const int SIZE);
void print_array(const vector<int> ARRAY);

class Cut_The_Sticks {

private:
    vector<int> _sticks_length_array;
    int _size_sticks_length_array;
    vector<int> _remaining_sticks_length_array;

    void _initialize_remaining_sticks_length_array() {
        _remaining_sticks_length_array.push_back(_size_sticks_length_array);
    }

    void _cut_the_sticks() {
        for (int i {0}; i < _size_sticks_length_array; ) {
            const int SHORTEST_STICK_LENGTH {_sticks_length_array.at(i)};

            i = {_find_first_element_index_different_of_first_current_shortest_stick_length_index(i)};
            const int CURRENT_ITERATION_SIZE {_size_sticks_length_array - i};
            if (i == _size_sticks_length_array)
                break;

            _remaining_sticks_length_array.push_back(CURRENT_ITERATION_SIZE);
            _decrease_sticks_lengths_higher_than_current_shortest_stick_length(i, SHORTEST_STICK_LENGTH);
        }
    }

        int _find_first_element_index_different_of_first_current_shortest_stick_length_index(int index) const {
            const int SHORTEST_STICK_LENGTH {_sticks_length_array.at(index)};
            while (index < _size_sticks_length_array && _sticks_length_array.at(index) == SHORTEST_STICK_LENGTH)
                index++;
            return index;
        }

        void _decrease_sticks_lengths_higher_than_current_shortest_stick_length(int index, const int SHORTEST_STICK_LENGTH) {
            auto lambda_expression = [SHORTEST_STICK_LENGTH](auto & element) {element -= SHORTEST_STICK_LENGTH;};
            for_each(_sticks_length_array.begin() + index, _sticks_length_array.end(), lambda_expression);
        }

public:
    Cut_The_Sticks(const vector<int> ARRAY) {
        _sticks_length_array = {ARRAY};
        _size_sticks_length_array = {static_cast<int>(ARRAY.size())};
        _initialize_remaining_sticks_length_array();
        _cut_the_sticks();
    }

    vector<int> get_remaining_sticks_length_array() const {
        return _remaining_sticks_length_array;
    }
};

int main() {
    const int SIZE {read_a_number()};
    vector<int> array {read_an_array(SIZE)};
    ranges::sort(array);

    const Cut_The_Sticks OBJ(array);
    const vector<int> RESULT {OBJ.get_remaining_sticks_length_array()};
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
        ranges::generate(array, []() {int number; cin >> number; return number;});
        return array;
    }

    void print_array(const vector<int> ARRAY) {
        for (auto element : ARRAY)
            cout << element << "\n";
    }
