// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

#include <stdio.h>

int find_digits(int n);

// n: number of test cases
// T: O(n)
// S: O(1)
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0, number; i < n && scanf("%d", &number); ++i)
        printf("%d\n", find_digits(number));

    return 0;
}

// d: quantity of digits of parameter n
// T: O(d)
// S: O(1)
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
