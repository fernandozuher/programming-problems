// Source: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int read_a_number();
void print_output(vector<int> output_set);

class Find_Digits {
private:
    int _number;
    int _divisors;

    void _find_number_divisors_quantity() {
        for (int currentNumber {_number}; currentNumber != 0; currentNumber = {_remove_last_digit_of_number(currentNumber)}) {
            const int DIVISOR {_get_last_digit_of_number(currentNumber)};
            if (_is_number_evenly_divided_by_divisor(DIVISOR))
                _divisors++;
        }
    }

        int _get_last_digit_of_number(const int NUMBER) const {
            return NUMBER % 10;
        }

        bool _is_number_evenly_divided_by_divisor(const int DIVISOR) const {
            return DIVISOR != 0 && _number % DIVISOR == 0;
        }

        int _remove_last_digit_of_number(const int NUMBER) const {
            return NUMBER / 10;
        }

public:
    Find_Digits(const int NUMBER): _number{NUMBER} {
        _divisors = {0};
        _find_number_divisors_quantity();
    }

    int get_divisors() const {
        return _divisors;
    }
};

int main() {
    const int N_TEST_CASES {read_a_number()};
    vector<int> output_set(N_TEST_CASES);

    for (auto& output : output_set) {
        const int NUMBER {read_a_number()};
        const Find_Digits OBJ(NUMBER);
        output = {OBJ.get_divisors()};
    }

    print_output(output_set);

    return 0;
}

    int read_a_number() {
        int number;
        cin >> number;
        return number;
    }

    void print_output(vector<int> output_set) {
        for (auto output : output_set) {
            cout << output << "\n";
        }
    }
