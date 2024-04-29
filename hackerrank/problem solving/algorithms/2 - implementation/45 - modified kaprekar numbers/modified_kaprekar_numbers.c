// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUANTITY_OF_KAPREKAR_NUMBERS 100

typedef struct {
    int size;
    int arr[MAX_QUANTITY_OF_KAPREKAR_NUMBERS];
} array;

array find_kaprekar_numbers_in_range(int lower_limit, int upper_limit);
    int calculate_potential_kaprekar_number(int number);
        int number_digits(long n);
void print_output(const array* const arr);

int main()
{
    int lower_limit, upper_limit;
    scanf("%d %d", &lower_limit, &upper_limit);
    array kaprekar_numbers_in_range = find_kaprekar_numbers_in_range(lower_limit, upper_limit);
    print_output(&kaprekar_numbers_in_range);

    return 0;
}

    array find_kaprekar_numbers_in_range(const int lower_limit, const int upper_limit)
    {
        array kaprekar_numbers = {0, 0};
        for (int number = lower_limit; number <= upper_limit; ++number) {
            if (number == calculate_potential_kaprekar_number(number))
                kaprekar_numbers.arr[kaprekar_numbers.size++] = number;
        }
        return kaprekar_numbers;
    }

        int calculate_potential_kaprekar_number(const int number)
        {
            long square_number = powl(number, 2);
            long divisor = powl(10, number_digits(number));

            ldiv_t x = ldiv(square_number, divisor);
            int left_number = x.quot;
            int right_number = x.rem;

            return left_number + right_number;
        }

            int number_digits(const long n)
            {
                if (n < 10) return 1;
                if (n < 100) return 2;
                if (n < 1000) return 3;
                if (n < 10000) return 4;
                if (n < 100000) return 5;
                if (n < 1000000) return 6;
                if (n < 10000000) return 7;
                return 8;
            }

    void print_output(const array* const arr)
    {
        if (arr->size)
            for (int i = 0; i < arr->size; ++i)
                printf("%d ", arr->arr[i]);
        else
            puts("INVALID RANGE");
    }
