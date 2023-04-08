// Source: https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int read_a_number();
void print_array(const vector<int> ARRAY);


class Sherlock_And_Squares {
private:
    int _begin;
    int _end;
    int _quantity_of_square_integers;

    void _calculate_number_of_square_integers_in_range() {
        const int FIRST_SQUARE_INTEGER {_find_first_square_integer_from_begin_number()};
        for (int number {FIRST_SQUARE_INTEGER}; _is_power_of_2_of_number_less_than_or_equal_to_end_number(number); number++)
            _quantity_of_square_integers++;
    }

        int _find_first_square_integer_from_begin_number() const {
            const double SQUARE_ROOT_NUMBER {sqrt(_begin)};
            const int SQUARE_INTEGER {_get_square_integer_from_number(SQUARE_ROOT_NUMBER)};
            return SQUARE_INTEGER;
        }

            int _get_square_integer_from_number(const double NUMBER) const {
                const double INTEGER_PART {trunc(NUMBER)};
                return NUMBER == INTEGER_PART ? INTEGER_PART : INTEGER_PART + 1;
            }

        bool _is_power_of_2_of_number_less_than_or_equal_to_end_number(const int NUMBER) const {
            return pow(NUMBER, 2) <= _end;
        }

public:
    Sherlock_And_Squares(const int BEGIN, const int END) {
        _begin = {BEGIN};
        _end = {END};
        _quantity_of_square_integers = {0};

        _calculate_number_of_square_integers_in_range();
    }

    int get_quantity_of_square_integers() const {
        return _quantity_of_square_integers;
    }
};

int main() {
    const int N_TEST_CASES {read_a_number()};
    vector<int> output(N_TEST_CASES);

    for (auto& element : output) {
        const int BEGIN {read_a_number()};
        const int END {read_a_number()};
        const Sherlock_And_Squares OBJ(BEGIN, END);
        element = {OBJ.get_quantity_of_square_integers()};
    }

    print_array(output);

    return 0;
}

    int read_a_number() {
        int number;
        cin >> number;
        return number;
    }

    void print_array(const vector<int> ARRAY) {
        ranges::for_each(ARRAY, [](auto element) {cout << element << "\n";});
    }
