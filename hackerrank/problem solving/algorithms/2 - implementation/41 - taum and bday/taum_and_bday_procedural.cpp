// Source: https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<unsigned long> read_a_test_case();
    unsigned long read_a_number();

unsigned long calculate_minimum_cost_of_buying_gifts(const vector<unsigned long> INPUT);
    bool are_original_costs_cheaper_or_equal_than_convertion_between_gifts(const vector<unsigned long> INPUT);
    unsigned long calculate_minimum_standard_cost(const vector<unsigned long> INPUT);
    unsigned long calculate_minimum_cost_in_converting_gifts(const vector<unsigned long> INPUT);

void print_array(const vector<unsigned long> ARRAY);


int main() {
    const unsigned long N_TEST_CASES {read_a_number()};
    vector<unsigned long> output(N_TEST_CASES);

    for (auto& element : output) {
        const vector<unsigned long> INPUT {read_a_test_case()};
        element = {calculate_minimum_cost_of_buying_gifts(INPUT)};
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

    unsigned long calculate_minimum_cost_of_buying_gifts(const vector<unsigned long> INPUT) {
        if (are_original_costs_cheaper_or_equal_than_convertion_between_gifts(INPUT))
            return calculate_minimum_standard_cost(INPUT);
        return calculate_minimum_cost_in_converting_gifts(INPUT);
    }

        bool are_original_costs_cheaper_or_equal_than_convertion_between_gifts(const vector<unsigned long> INPUT) {
            const unsigned long BLACK_GIFT_COST {INPUT.at(2)};
            const unsigned long WHITE_GIFT_COST {INPUT.at(3)};
            const unsigned long COST_TO_CONVERT_BETWEEN_GIFTS {INPUT.back()};

            const unsigned long COST_TO_CONVERT_FROM_BLACK_TO_WHITE {BLACK_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS};
            const unsigned long COST_TO_CONVERT_FROM_WHITE_TO_BLACK {WHITE_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS};

            return WHITE_GIFT_COST <= COST_TO_CONVERT_FROM_BLACK_TO_WHITE && BLACK_GIFT_COST <= COST_TO_CONVERT_FROM_WHITE_TO_BLACK;
        }

        unsigned long calculate_minimum_standard_cost(const vector<unsigned long> INPUT) {
            const unsigned long N_BLACK_GIFTS {INPUT.front()};
            const unsigned long N_WHITE_GIFTS {INPUT.at(1)};
            const unsigned long BLACK_GIFT_COST {INPUT.at(2)};
            const unsigned long WHITE_GIFT_COST {INPUT.at(3)};

            return N_BLACK_GIFTS * BLACK_GIFT_COST + N_WHITE_GIFTS * WHITE_GIFT_COST;
        }

        unsigned long calculate_minimum_cost_in_converting_gifts(vector<unsigned long> INPUT) {
            const unsigned long N_BLACK_GIFTS {INPUT.front()};
            const unsigned long N_WHITE_GIFTS {INPUT.at(1)};
            const unsigned long BLACK_GIFT_COST {INPUT.at(2)};
            const unsigned long WHITE_GIFT_COST {INPUT.at(3)};
            const unsigned long COST_TO_CONVERT_BETWEEN_GIFTS {INPUT.back()};

            const unsigned long COST_TO_CONVERT_FROM_BLACK_TO_WHITE {BLACK_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS};
            const unsigned long TOTAL_GIFTS {N_BLACK_GIFTS + N_WHITE_GIFTS};

            unsigned long minimum_cost_of_buying_gifts;

            if (WHITE_GIFT_COST > COST_TO_CONVERT_FROM_BLACK_TO_WHITE)
                minimum_cost_of_buying_gifts = {TOTAL_GIFTS * BLACK_GIFT_COST + N_WHITE_GIFTS * COST_TO_CONVERT_BETWEEN_GIFTS};
            else
                minimum_cost_of_buying_gifts = {TOTAL_GIFTS * WHITE_GIFT_COST + N_BLACK_GIFTS * COST_TO_CONVERT_BETWEEN_GIFTS};

            return minimum_cost_of_buying_gifts;
        }

    void print_array(const vector<unsigned long> ARRAY) {
        ranges::for_each(ARRAY, [](auto element) {cout << element << "\n";});
    }
