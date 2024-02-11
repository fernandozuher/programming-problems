// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int calculate_factorial(int* factorial, const int number);
    int multiply_array_with_number(int *array, int n, const int number);
        int get_last_digit_of_number(const int number);
        int remove_last_digit_of_number(const int number);
        int add_remaining_carry_to_array(int carry, int *array, int n);
void print_factorial(const int *array, int n);

int main()
{
    int number;
    scanf("%d", &number);
    const int max_digits_of_factorial_100 = 158;
    int *factorial = (int*) calloc(max_digits_of_factorial_100, sizeof(int));

    int n = calculate_factorial(factorial, number);
    print_factorial(factorial, n);

    free(factorial);
    factorial = NULL;

    return 0;
}

    int calculate_factorial(int* factorial, const int number)
    {
        factorial[0] = 1;
        int n = 1;

        for (int current_number = 2; current_number <= number; ++current_number)
            n = multiply_array_with_number(factorial, n, current_number);

        return n;
    }

        int multiply_array_with_number(int *array, int n, const int number)
        {
            int carry = 0;

            for (int i = 0; i < n; ++i) {
                int product = array[i] * number + carry;
                array[i] = get_last_digit_of_number(product);
                carry = remove_last_digit_of_number(product);
            }

            n = add_remaining_carry_to_array(carry, array, n);
            return n;
        }

            int get_last_digit_of_number(const int number)
            {
                return number % 10;
            }

            int remove_last_digit_of_number(const int number)
            {
                return number / 10;
            }

            int add_remaining_carry_to_array(int carry, int *array, int n)
            {
                for (; carry; ++n) {
                    array[n] = get_last_digit_of_number(carry);
                    carry = remove_last_digit_of_number(carry);
                }
                return n;
            }

    void print_factorial(const int *array, int n)
    {
        while (n--)
            printf("%d", array[n]);
        puts("");
    }
