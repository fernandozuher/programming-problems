// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

enum { n_ratios = 3 };

void plus_minus(const float *arr, size_t n, float *ratios);
void print_ratios(const float *ratios, size_t n);

int main()
{
    morfo_skip_input_ln();

    size_t n;
    float *arr = morfo_readln(float, &n);

    float ratios[n_ratios];
    plus_minus(arr, n, ratios);
    print_ratios(ratios, n_ratios);

    free(arr);
    return 0;
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
void plus_minus(const float *arr, size_t n, float *ratios)
{
    int positive, negative, zero;
    positive = negative = zero = 0;

    for (size_t i = 0; i < n; ++i) {
        if (arr[i] > 0)
            ++positive;
        else if (arr[i] < 0)
            ++negative;
        else
            ++zero;
    }

    float total = (float) n;
    ratios[0] = positive / total;
    ratios[1] = negative / total;
    ratios[2] = zero / total;
}

void print_ratios(const float *ratios, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        printf("%.6f\n", ratios[i]);
}
