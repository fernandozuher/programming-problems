// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

void sequence_equation(const int *arr, int *res, int n);

int main()
{
    morfo_skip_input_ln();
    size_t n;
    int *arr = morfo_readln(int, &n);

    int res[n];
    sequence_equation(arr, res, (int)n);
    morfo_println(res, n);

    free(arr);
    return 0;
}

// n: length of arr/res
// T: O(n)
// S: O(n) extra space
void sequence_equation(const int *arr, int *res, int n)
{
    int values_to_index[n];
    for (int i = 0; i < n; ++i)
        values_to_index[arr[i] - 1] = i;

    for (int i = 0; i < n; ++i)
        res[i] = values_to_index[values_to_index[i]] + 1;
}
