// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

int sum_stdin();

int main()
{
    morfo_skip_input_ln();
    printf("%d", sum_stdin());
    return 0;
}

// n: number of integers in the input line
// T: O(n)
// S: O(n) extra space
int sum_stdin()
{
    size_t n;
    int *arr = morfo_readln(int, &n);
    int sum = 0;

    for (size_t i = 0; i < n; ++i)
        sum += arr[i];

    free(arr);

    return sum;
}
