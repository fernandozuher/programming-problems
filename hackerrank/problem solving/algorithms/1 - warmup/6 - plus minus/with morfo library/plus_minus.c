// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

morfo_float_slice_t plus_minus(const morfo_float_slice_t *arr);
void print_ratios(const morfo_float_slice_t *ratios);

int main()
{
    morfo_skip_input_ln();
    morfo_float_slice_t arr = morfo_readln(float);
    morfo_float_slice_t ratios = plus_minus(&arr);
    print_ratios(&ratios);
    
    free(arr.data);
    free(ratios.data);

    return 0;
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
morfo_float_slice_t plus_minus(const morfo_float_slice_t *arr)
{
    int positive, negative, zero;
    positive = negative = zero = 0;

    for (int i = 0; i < arr->len; ++i) {
        if (arr->data[i] > 0)
            ++positive;
        else if (arr->data[i] < 0)
            ++negative;
        else
            ++zero;
    }

    float total = (float) arr->len;

    morfo_float_slice_t ratios;
    ratios.len = 3;
    ratios.data = malloc(ratios.len * sizeof(float));

    ratios.data[0] = positive / total;
    ratios.data[1] = negative / total;
    ratios.data[2] = zero / total;

    return ratios;
}

void print_ratios(const morfo_float_slice_t *ratios)
{
    for (int i = 0; i < ratios->len; ++i)
        printf("%.6f\n", ratios->data[i]);
}
