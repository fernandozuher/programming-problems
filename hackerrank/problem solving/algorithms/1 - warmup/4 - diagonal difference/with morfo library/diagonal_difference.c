// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

int diagonal_difference(int n);

int main()
{
    int n = morfo_read(int);
    printf("%d\n", diagonal_difference(n));
    return 0;
}

// T: O(n^2)
// S: O(n) extra space
int diagonal_difference(int n)
{
    int primary_sum = 0, secondary_sum = 0;

    for (int i = 0, arr[n]; i < n; ++i) {
        int *arr = morfo_read_ln_alloc(int, &n);
        primary_sum += arr[i];
        secondary_sum += arr[n - i - 1];
        free(arr);
    }

    return abs(primary_sum - secondary_sum);
}
