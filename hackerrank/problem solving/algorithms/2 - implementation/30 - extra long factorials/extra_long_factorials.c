// Source: https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int read_a_number();
    int calculate_factorial(int* factorial, const int NUMBER);
        int multiply_array_with_number(int* array, int array_size, const int NUMBER);
            int get_last_digit_of_number(const int NUMBER);
            int remove_last_digit_of_number(const int NUMBER);
            int add_remaining_carry_to_array(int carry, int* array, int array_size);
void print_factorial(const int* ARRAY, int array_size);


int main() {
    const int NUMBER = read_a_number();
    const int MAX_DIGITS_OF_FACTORIAL_100 = 158;
    int* factorial = (int*) calloc(MAX_DIGITS_OF_FACTORIAL_100, sizeof(int));

    int factorial_size = calculate_factorial(factorial, NUMBER);
    print_factorial(factorial, factorial_size);

    free(factorial);
    factorial = NULL;

    return 0;
}

    int read_a_number() {
        int number;
        scanf("%d", &number);
        return number;
    }

    int calculate_factorial(int* factorial, const int NUMBER) {
        factorial[0] = 1;
        int factorial_size = 1;

        for (int number = 2; number <= NUMBER; number++)
            factorial_size = multiply_array_with_number(factorial, factorial_size, number);

        return factorial_size;
    }

        int multiply_array_with_number(int* array, int array_size, const int NUMBER) {
            int carry = 0;

            for (int i = 0; i < array_size; i++) {
                const int PRODUCT = array[i] * NUMBER + carry;
                array[i] = get_last_digit_of_number(PRODUCT);
                carry = remove_last_digit_of_number(PRODUCT);
            }

            array_size = add_remaining_carry_to_array(carry, array, array_size);
            return array_size;
        }

            int get_last_digit_of_number(const int NUMBER) {
                return NUMBER % 10;
            }

            int remove_last_digit_of_number(const int NUMBER) {
                return NUMBER / 10;
            }

            int add_remaining_carry_to_array(int carry, int* array, int array_size) {
                while (carry != 0) {
                    array[array_size++] = get_last_digit_of_number(carry);
                    carry = remove_last_digit_of_number(carry);
                }
                return array_size;
            }

    void print_factorial(const int* ARRAY, int array_size) {
        while (array_size--)
            printf("%d", ARRAY[array_size]);
        puts("");
    }
