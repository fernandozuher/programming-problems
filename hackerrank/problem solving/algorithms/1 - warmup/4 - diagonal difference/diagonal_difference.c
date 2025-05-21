// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int diagonal_difference(int n);
void read_numbers(int numbers[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", diagonal_difference(n));
    return 0;
}

int diagonal_difference(int n)
{
    int primary_sum = 0, secondary_sum = 0;

    int numbers[n];
    for (int i = 0; i < n; ++i) {
        read_numbers(numbers, n);
        primary_sum += numbers[i];
        secondary_sum += numbers[n - i - 1];
    }

    return abs(primary_sum - secondary_sum);
}

void read_numbers(int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
}
