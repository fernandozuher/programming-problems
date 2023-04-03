// Source: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

#include <stdio.h>
#include <stdbool.h>

int read_a_number();
int find_number_divisors_quantity(const int NUMBER);
    bool is_number_evenly_divided_by_divisor(const int NUMBER, const int DIVISOR);
void print_output(const int *ARRAY, const int SIZE);


int main() {
    const int N_TEST_CASES = read_a_number();
    int output[N_TEST_CASES];

    for (int i = 0; i < N_TEST_CASES; i++) {
        const int NUMBER = read_a_number();
        output[i] = find_number_divisors_quantity(NUMBER);
    }

    print_output(output, N_TEST_CASES);

    return 0;
}

    int read_a_number() {
        int number;
        scanf("%d", &number);
        return number;
    }

    int find_number_divisors_quantity(const int NUMBER) {
        int divisors = 0;

        for (int number = NUMBER; number != 0; number = remove_last_digit_of_number(number)) {
            const int DIVISOR = get_last_digit_of_number(number);
            if (is_number_evenly_divided_by_divisor(NUMBER, DIVISOR))
                divisors++;
        }

        return divisors;
    }

        int get_last_digit_of_number(const int NUMBER) {
            return NUMBER % 10;
        }

        bool is_number_evenly_divided_by_divisor(const int NUMBER, const int DIVISOR) {
            return DIVISOR != 0 && NUMBER % DIVISOR == 0;
        }

        int remove_last_digit_of_number(const int NUMBER) {
            return NUMBER / 10;
        }

    void print_output(const int *ARRAY, const int SIZE) {
        for (int i = 0; i < SIZE; i++)
            printf("%d\n", ARRAY[i]);
    }
