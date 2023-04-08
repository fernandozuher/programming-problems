// Source: https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int read_a_number();
int calculate_number_of_square_integers_in_range(const int BEGIN, const int END);
    int find_first_square_integer_from_number(const int BEGIN);
        int get_square_integer_from_number(const double NUMBER);
    bool is_power_of_2_of_number_less_than_or_equal_to_limit(const int NUMBER, const int LIMIT);
void print_array(const int* ARRAY, const int SIZE);


int main() {
    const int N_TEST_CASES = read_a_number();
    int output[N_TEST_CASES];

    for (int i = 0; i < N_TEST_CASES; i++) {
        const int BEGIN = read_a_number();
        const int END = read_a_number();
        output[i] = calculate_number_of_square_integers_in_range(BEGIN, END);
    }

    print_array(output, N_TEST_CASES);

    return 0;
}

    int read_a_number() {
        int number;
        scanf("%d", &number);
        return number;
    }

    int calculate_number_of_square_integers_in_range(const int BEGIN, const int END) {
        const int FIRST_SQUARE_INTEGER = find_first_square_integer_from_number(BEGIN);
        int squares = 0;
        for (int number = FIRST_SQUARE_INTEGER; is_power_of_2_of_number_less_than_or_equal_to_limit(number, END); number++)
            squares++;
        return squares;
    }

        int find_first_square_integer_from_number(const int NUMBER) {
            const double SQUARE_ROOT_NUMBER = sqrt(NUMBER);
            const int SQUARE_INTEGER = get_square_integer_from_number(SQUARE_ROOT_NUMBER);
            return SQUARE_INTEGER;
        }

            int get_square_integer_from_number(const double NUMBER) {
                const double INTEGER_PART = trunc(NUMBER);
                return NUMBER == INTEGER_PART ? INTEGER_PART : INTEGER_PART + 1;
            }

        bool is_power_of_2_of_number_less_than_or_equal_to_limit(const int NUMBER, const int LIMIT) {
            return pow(NUMBER, 2) <= LIMIT;
        }

    void print_array(const int* ARRAY, const int SIZE) {
        for (int i = 0; i < SIZE; i++)
            printf("%d\n", ARRAY[i]);
    }
