// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int diagonal_difference(int n);
void read_numbers(int *arr, int n);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", diagonal_difference(n));
    return 0;
}

// T: O(n^2)
// S: O(n) extra space
int diagonal_difference(int n)
{
    int primary_sum = 0, secondary_sum = 0;

    for (int i = 0, arr[n]; i < n; ++i) {
        read_numbers(arr, n);
        primary_sum += arr[i];
        secondary_sum += arr[n - i - 1];
    }

    return abs(primary_sum - secondary_sum);
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}
