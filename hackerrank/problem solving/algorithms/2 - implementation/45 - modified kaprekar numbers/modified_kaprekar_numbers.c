// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true
// Written in C23: false and true first-class language features

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

bool is_number_kaprekar(int number);
    int number_digits(long n);

int main()
{
    int lower_limit, upper_limit;
    scanf("%d %d", &lower_limit, &upper_limit);
    bool valid_range = false;

    for (int number = lower_limit; number <= upper_limit; ++number) {
        if (is_number_kaprekar(number)) {
            printf("%d ", number);
            valid_range = true;
        }
    }

    if (!valid_range)
        puts("INVALID RANGE");

    return 0;
}

    bool is_number_kaprekar(const int number)
    {
        long square_number = powl(number, 2);
        long divisor = powl(10, number_digits(number));

        ldiv_t x = ldiv(square_number, divisor);
        int left_number = x.quot;
        int right_number = x.rem;

        return number == left_number + right_number;
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
