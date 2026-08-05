// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"
#include "morfo/math.h"

long long sum_stdin();

int main()
{
    morfo_skip_input_ln();
    printf("%lld", sum_stdin());
    return 0;
}

// n: number of integers in the input line
// T: O(n)
// S: O(n) extra space
long long sum_stdin()
{
    size_t n;
    int *arr = morfo_readln(int, &n);
    long long sum = morfo_sum(arr, n);
    free(arr);
    return sum;
}
