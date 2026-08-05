// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"
#include "morfo/math.h"

long long a_very_big_sum(const long long *arr, size_t n);

int main()
{
    morfo_skip_input_ln();

    size_t n;
    long long *arr = morfo_readln(long long, &n);

    printf("%lld\n", a_very_big_sum(arr, n));

    free(arr);
    return 0;
}

// T: O(n)
// S: O(1) extra space
long long a_very_big_sum(const long long *arr, size_t n)
{
    return morfo_sum(arr, n);
}
