// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"
#include "morfo/collections.h"
#include "morfo/math.h"

int birthday_cake_candles(const int *candles, int n);

int main()
{
    morfo_skip_input_ln();
    size_t n;
    int *candles = morfo_readln(int, &n);
    printf("%d\n", birthday_cake_candles(candles, (int)n));
    free(candles);
    return 0;
}

// n: length of candles
// T: O(2n) => O(n)
// S: O(1) extra space
int birthday_cake_candles(const int *candles, int n)
{
    int max_value = morfo_max(candles, n);
    return (int)morfo_count(candles, (size_t)n, max_value);
}
