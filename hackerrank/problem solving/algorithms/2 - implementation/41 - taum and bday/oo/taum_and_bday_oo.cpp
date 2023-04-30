// Source: https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<unsigned long> read_a_test_case();
    unsigned long read_a_number();
void print_array(const vector<unsigned long> ARRAY);

class Taum_And_Bday {
private:
    unsigned long _n_black_gifts, _n_white_gifts;
    unsigned long _black_gift_cost, _white_gift_cost;
    unsigned long _cost_to_convert_between_gifts;

    unsigned long _cost_to_convert_from_black_to_white, _cost_to_convert_from_white_to_black;

    unsigned long _minimum_cost_of_buying_gifts;

    unsigned long _calculate_minimum_cost_of_buying_gifts() const {
        if (_are_original_costs_cheaper_or_equal_than_convertion_between_gifts())
            return _calculate_minimum_standard_cost();
        return _calculate_minimum_cost_in_converting_gifts();
    }

        bool _are_original_costs_cheaper_or_equal_than_convertion_between_gifts() const {
            return _white_gift_cost <= _cost_to_convert_from_black_to_white && _black_gift_cost <= _cost_to_convert_from_white_to_black;
        }

        unsigned long _calculate_minimum_standard_cost() const {
            return _n_black_gifts * _black_gift_cost + _n_white_gifts * _white_gift_cost;
        }

        unsigned long _calculate_minimum_cost_in_converting_gifts() const {
            const unsigned long TOTAL_GIFTS {_n_black_gifts + _n_white_gifts};

            if (_white_gift_cost > _cost_to_convert_from_black_to_white)
                return TOTAL_GIFTS * _black_gift_cost + _n_white_gifts * _cost_to_convert_between_gifts;

            return TOTAL_GIFTS * _white_gift_cost + _n_black_gifts * _cost_to_convert_between_gifts;
        }

public:
    Taum_And_Bday(const vector<unsigned long> INPUT) {
        _n_black_gifts = {INPUT.front()};
        _n_white_gifts = {INPUT.at(1)};
        _black_gift_cost = {INPUT.at(2)};
        _white_gift_cost = {INPUT.at(3)};
        _cost_to_convert_between_gifts = {INPUT.back()};

        _cost_to_convert_from_black_to_white = {_black_gift_cost + _cost_to_convert_between_gifts};
        _cost_to_convert_from_white_to_black = {_white_gift_cost + _cost_to_convert_between_gifts};

        _minimum_cost_of_buying_gifts = _calculate_minimum_cost_of_buying_gifts();
    }

    unsigned long get_minimum_cost_of_buying_gifts() const {
        return _minimum_cost_of_buying_gifts;
    }
};

int main() {
    const unsigned long N_TEST_CASES {read_a_number()};
    vector<unsigned long> output(N_TEST_CASES);

    for (auto& element : output) {
        const vector<unsigned long> INPUT {read_a_test_case()};
        const Taum_And_Bday OBJ(INPUT);
        element = {OBJ.get_minimum_cost_of_buying_gifts()};
    }

    print_array(output);
    return 0;
}

    vector<unsigned long> read_a_test_case() {
        const unsigned long N_BLACK_GIFTS {read_a_number()};
        const unsigned long N_WHITE_GIFTS {read_a_number()};
        const unsigned long BLACK_GIFT_COST {read_a_number()};
        const unsigned long WHITE_GIFT_COST {read_a_number()};
        const unsigned long COST_TO_CONVERT_BETWEEN_GIFTS {read_a_number()};

        return vector<unsigned long> {N_BLACK_GIFTS, N_WHITE_GIFTS, BLACK_GIFT_COST, WHITE_GIFT_COST, COST_TO_CONVERT_BETWEEN_GIFTS};
    }

        unsigned long read_a_number() {
            unsigned long number;
            cin >> number;
            return number;
        }

    void print_array(const vector<unsigned long> ARRAY) {
        ranges::for_each(ARRAY, [](auto element) {cout << element << "\n";});
    }
