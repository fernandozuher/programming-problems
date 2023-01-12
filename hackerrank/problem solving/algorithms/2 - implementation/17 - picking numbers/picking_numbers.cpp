// Source: https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Result {

private:
    vector<int> _numbers;
    int _subarray_biggest_size;

    void _picking_numbers() {
        int first_reference_number_index {0};
        int second_reference_number_index {0};
        int subarray_current_size {1};

        for (int i {1}, n = _numbers.size(); i < n; i++) {
            int difference {_numbers.at(i) - _numbers.at(first_reference_number_index)};

            switch (difference) {
                case 0:
                    subarray_current_size++;
                    break;

                case 1:
                    subarray_current_size++;
                    if (_numbers.at(second_reference_number_index) != _numbers.at(i))
                        second_reference_number_index = i;
                    break;

                default:
                    _subarray_biggest_size = update_subarray_biggest_size(subarray_current_size);

                    const vector<int> update = update_first_reference_number_index_and_subarray_current_size(i, second_reference_number_index);

                    first_reference_number_index = update.front();
                    second_reference_number_index = i;
                    subarray_current_size = update.back();
            }
        }

        _subarray_biggest_size = update_subarray_biggest_size(subarray_current_size);
    }

        int update_subarray_biggest_size(const int subarray_current_size) const {
            return max(subarray_current_size, _subarray_biggest_size);
        }

        vector<int> update_first_reference_number_index_and_subarray_current_size(const int i, const int second_reference_number_index) const {
            int first_reference_number_index, subarray_current_size;

            if (_numbers.at(i) - _numbers.at(second_reference_number_index) == 1) {
                first_reference_number_index = second_reference_number_index;
                subarray_current_size = i - second_reference_number_index + 1;
            }
            else {
                first_reference_number_index = i;
                subarray_current_size = 1;
            }

            vector<int> result {first_reference_number_index, subarray_current_size};
            return result;
        }

public:
    Result(const vector<int> _numbers): _numbers{_numbers} {
        _subarray_biggest_size = 1;

        _picking_numbers();
        print_result();
    }

        void print_result() const {
            cout << _subarray_biggest_size;
        }
};

vector<int> read_line_as_vector_int() {
    vector<int> input_line;
    string line;
    getline(cin, line);
    stringstream ss(line);

    for (int number; ss >> number; input_line.push_back(number));
    return input_line;
}

int main() {
    read_line_as_vector_int();

    vector<int> numbers {read_line_as_vector_int()};
    sort(numbers.begin(), numbers.end());

    Result result(numbers);

    return 0;
}
