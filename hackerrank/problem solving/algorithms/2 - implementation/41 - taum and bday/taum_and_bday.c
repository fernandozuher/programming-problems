// Source: https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned long* initialize_empty_array(const unsigned long SIZE);
unsigned long* read_a_test_case();
    unsigned long read_a_number();

unsigned long calculate_minimum_cost_of_buying_gifts(const unsigned long* INPUT);
    bool are_original_costs_cheaper_or_equal_than_convertion_between_gifts(const unsigned long* INPUT);
    unsigned long calculate_minimum_standard_cost(const unsigned long* INPUT);
    unsigned long calculate_minimum_cost_in_converting_gifts(const unsigned long* INPUT);

void print_array(const unsigned long* ARRAY, const unsigned long SIZE);
unsigned long* free_array(unsigned long* array);


int main() {
    const unsigned long N_TEST_CASES = read_a_number();
    unsigned long* output = initialize_empty_array(N_TEST_CASES);

    for (unsigned long int i = 0; i < N_TEST_CASES; i++) {
        unsigned long* input = read_a_test_case();
        output[i] = calculate_minimum_cost_of_buying_gifts(input);

        input = free_array(input);
    }

    print_array(output, N_TEST_CASES);

    output = free_array(output);
    return 0;
}

    unsigned long* initialize_empty_array(const unsigned long SIZE) {
        unsigned long* array = (unsigned long*) calloc(SIZE, sizeof(unsigned long));
        return array;
    }

    unsigned long* read_a_test_case() {
        const unsigned long N_BLACK_GIFTS = read_a_number();
        const unsigned long N_WHITE_GIFTS = read_a_number();
        const unsigned long BLACK_GIFT_COST = read_a_number();
        const unsigned long WHITE_GIFT_COST = read_a_number();
        const unsigned long COST_TO_CONVERT_BETWEEN_GIFTS = read_a_number();

        unsigned long* array = (unsigned long*) calloc(5, sizeof(unsigned long));
        array[0] = N_BLACK_GIFTS;
        array[1] = N_WHITE_GIFTS;
        array[2] = BLACK_GIFT_COST;
        array[3] = WHITE_GIFT_COST;
        array[4] = COST_TO_CONVERT_BETWEEN_GIFTS;

        return array;
    }

        unsigned long read_a_number() {
            unsigned long number;
            scanf("%lu", &number);
            return number;
        }

    unsigned long calculate_minimum_cost_of_buying_gifts(const unsigned long* INPUT) {
        if (are_original_costs_cheaper_or_equal_than_convertion_between_gifts(INPUT))
            return calculate_minimum_standard_cost(INPUT);
        return calculate_minimum_cost_in_converting_gifts(INPUT);
    }

        bool are_original_costs_cheaper_or_equal_than_convertion_between_gifts(const unsigned long* INPUT) {
            const unsigned long BLACK_GIFT_COST = INPUT[2];
            const unsigned long WHITE_GIFT_COST = INPUT[3];
            const unsigned long COST_TO_CONVERT_BETWEEN_GIFTS = INPUT[4];

            const unsigned long COST_TO_CONVERT_FROM_BLACK_TO_WHITE = BLACK_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS;
            const unsigned long COST_TO_CONVERT_FROM_WHITE_TO_BLACK = WHITE_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS;

            return WHITE_GIFT_COST <= COST_TO_CONVERT_FROM_BLACK_TO_WHITE && BLACK_GIFT_COST <= COST_TO_CONVERT_FROM_WHITE_TO_BLACK;
        }

        unsigned long calculate_minimum_standard_cost(const unsigned long* INPUT) {
            const unsigned long N_BLACK_GIFTS = INPUT[0];
            const unsigned long N_WHITE_GIFTS = INPUT[1];
            const unsigned long BLACK_GIFT_COST = INPUT[2];
            const unsigned long WHITE_GIFT_COST = INPUT[3];

            return N_BLACK_GIFTS * BLACK_GIFT_COST + N_WHITE_GIFTS * WHITE_GIFT_COST;
        }

        unsigned long calculate_minimum_cost_in_converting_gifts(const unsigned long* INPUT) {
            const unsigned long N_BLACK_GIFTS = INPUT[0];
            const unsigned long N_WHITE_GIFTS = INPUT[1];
            const unsigned long BLACK_GIFT_COST = INPUT[2];
            const unsigned long WHITE_GIFT_COST = INPUT[3];
            const unsigned long COST_TO_CONVERT_BETWEEN_GIFTS = INPUT[4];

            const unsigned long COST_TO_CONVERT_FROM_BLACK_TO_WHITE = BLACK_GIFT_COST + COST_TO_CONVERT_BETWEEN_GIFTS;
            const unsigned long TOTAL_GIFTS = N_BLACK_GIFTS + N_WHITE_GIFTS;

            unsigned long minimum_cost_of_buying_gifts;

            if (WHITE_GIFT_COST > COST_TO_CONVERT_FROM_BLACK_TO_WHITE)
                minimum_cost_of_buying_gifts = TOTAL_GIFTS * BLACK_GIFT_COST + N_WHITE_GIFTS * COST_TO_CONVERT_BETWEEN_GIFTS;
            else
                minimum_cost_of_buying_gifts = TOTAL_GIFTS * WHITE_GIFT_COST + N_BLACK_GIFTS * COST_TO_CONVERT_BETWEEN_GIFTS;

            return minimum_cost_of_buying_gifts;
        }

    void print_array(const unsigned long* ARRAY, const unsigned long SIZE) {
        for (int i = 0; i < SIZE; i++)
            printf("%lu\n", ARRAY[i]);
    }

    unsigned long* free_array(unsigned long* array) {
        free(array);
        return NULL;
    }
