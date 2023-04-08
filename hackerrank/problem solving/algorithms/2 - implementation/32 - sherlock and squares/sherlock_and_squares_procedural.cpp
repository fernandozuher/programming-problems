// Source: https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int read_a_number();
int calculate_number_of_square_integers_in_range(const int BEGIN, const int END);
    int find_first_square_integer_from_number(const int BEGIN);
        int get_square_integer_from_number(const double NUMBER);
    bool is_power_of_2_of_number_less_than_or_equal_to_limit(const int NUMBER, const int LIMIT);
void print_array(const vector<int> ARRAY);


int main() {
    const int N_TEST_CASES {read_a_number()};
    vector<int> output(N_TEST_CASES);

    for (auto& element : output) {
        const int BEGIN {read_a_number()};
        const int END {read_a_number()};
        element = {calculate_number_of_square_integers_in_range(BEGIN, END)};
    }

    print_array(output);

    return 0;
}

    int read_a_number() {
        int number;
        cin >> number;
        return number;
    }

    int calculate_number_of_square_integers_in_range(const int BEGIN, const int END) {
        const int FIRST_SQUARE_INTEGER {find_first_square_integer_from_number(BEGIN)};
        int squares {0};
        for (int number {FIRST_SQUARE_INTEGER}; is_power_of_2_of_number_less_than_or_equal_to_limit(number, END); number++)
            squares++;
        return squares;
    }

        int find_first_square_integer_from_number(const int NUMBER) {
            const double SQUARE_ROOT_NUMBER {sqrt(NUMBER)};
            const int SQUARE_INTEGER {get_square_integer_from_number(SQUARE_ROOT_NUMBER)};
            return SQUARE_INTEGER;
        }

            int get_square_integer_from_number(const double NUMBER) {
                const double INTEGER_PART {trunc(NUMBER)};
                return NUMBER == INTEGER_PART ? INTEGER_PART : INTEGER_PART + 1;
            }

        bool is_power_of_2_of_number_less_than_or_equal_to_limit(const int NUMBER, const int LIMIT) {
            return pow(NUMBER, 2) <= LIMIT;
        }

    void print_array(const vector<int> ARRAY) {
        ranges::for_each(ARRAY, [](auto element){cout << element << "\n";});
    }
