// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

#include <stdio.h>
#include "morfo/io.h"

long long a_very_big_sum(const morfo_long_slice_t *arr);

int main()
{
    morfo_skip_input_ln();
    morfo_long_slice_t arr = morfo_readln(long long);
    printf("%lld\n", a_very_big_sum(&arr));
    return 0;
}

// T: O(n)
// S: O(1) extra space
long long a_very_big_sum(const morfo_long_slice_t *arr)
{
    long long sum = 0;
    for (int i = 0; i < arr->len; ++i)
        sum += arr->data[i];
    return sum;
}
