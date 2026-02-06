// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true
// C23

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

bool is_number_kaprekar(int n);
int number_digits(int n);

int main()
{
    int lower, upper;
    scanf("%d %d", &lower, &upper);
    bool valid_range = false;

    for (int num = lower; num <= upper; ++num)
        if (is_number_kaprekar(num)) {
            printf("%d ", num);
            valid_range = true;
        }

    if (!valid_range)
        puts("INVALID RANGE");

    return 0;
}

// log n: for calculating number of digits
// T: O(log n)
// S: O(1) extra space
bool is_number_kaprekar(int n)
{
    auto square_number = (long long) powl(n, 2);
    auto divisor = (long long) powl(10, number_digits(n));

    lldiv_t x = lldiv(square_number, divisor);
    auto left_number = x.quot;
    auto right_number = x.rem;

    return n == left_number + right_number;
}

int number_digits(int n)
{
    return (int) log10(n) + 1;
}
