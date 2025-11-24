// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

#include <stdio.h>

int find_digits(int n);

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0, number; i < n && scanf("%d", &number); ++i)
        printf("%d\n", find_digits(number));

    return 0;
}

int find_digits(int n)
{
    int divisors = 0;

    for (int original_number = n; n != 0; n /= 10) {
        int divisor = n % 10;
        if (divisor != 0 && original_number % divisor == 0)
            ++divisors;
    }

    return divisors;
}
