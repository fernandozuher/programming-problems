// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

#include <stdio.h>

int find_digits(int num);

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0, num; i < n; ++i) {
        scanf("%d", &num);
        printf("%d\n", find_digits(num));
    }

    return 0;
}

// k: quantity of digits of num = log num
// 0 < num < 10^9
// T: O(k) = O(9) = O(1)
// S: O(1) extra space
int find_digits(int num)
{
    int divisors = 0;

    for (int original_number = num; num != 0; num /= 10) {
        int divisor = num % 10;
        if (divisor != 0 && original_number % divisor == 0)
            ++divisors;
    }

    return divisors;
}
