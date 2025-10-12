// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true
// C23

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

bool is_number_kaprekar(int number);
int number_digits(long n);

int main()
{
    int lower, upper;
    scanf("%d %d", &lower, &upper);
    bool valid_range = false;

    for (int number = lower; number <= upper; ++number)
        if (is_number_kaprekar(number)) {
            printf("%d ", number);
            valid_range = true;
        }

    if (!valid_range)
        puts("INVALID RANGE");

    return 0;
}

bool is_number_kaprekar(int number)
{
    long square_number = powl(number, 2);
    long divisor = powl(10, number_digits(number));

    ldiv_t x = ldiv(square_number, divisor);
    int left_number = x.quot;
    int right_number = x.rem;

    return number == left_number + right_number;
}

int number_digits(long n)
{
    return (int) log10(n) + 1;
}
