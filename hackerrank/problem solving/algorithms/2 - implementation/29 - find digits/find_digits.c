// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

#include <stdio.h>
#include <stdbool.h>

int find_number_divisors_quantity(const int number);
    int get_last_digit_of_number(const int number);
    bool is_number_evenly_divided_by_divisor(const int number, const int divisor);
    int remove_last_digit_of_number(const int number);
void print_array(const int* const array, const int n);

int main()
{
    int n;
    scanf("%d", &n);
    int n_number_divisors[n];

    for (int i = 0; i < n; ++i) {
        int number;
        scanf("%d", &number);
        n_number_divisors[i] = find_number_divisors_quantity(number);
    }

    print_array(n_number_divisors, n);

    return 0;
}

    int find_number_divisors_quantity(const int number)
    {
        int divisors = 0;

        for (int current_number = number; current_number != 0; current_number = remove_last_digit_of_number(current_number)) {
            int divisor = get_last_digit_of_number(current_number);
            if (is_number_evenly_divided_by_divisor(number, divisor))
                ++divisors;
        }

        return divisors;
    }

        int get_last_digit_of_number(const int number)
        {
            return number % 10;
        }

        bool is_number_evenly_divided_by_divisor(const int number, const int divisor)
        {
            return divisor != 0 && number % divisor == 0;
        }

        int remove_last_digit_of_number(const int number)
        {
            return number / 10;
        }

    void print_array(const int* const array, const int n)
    {
        for (int i = 0; i < n; printf("%d\n", array[i++]));
    }
