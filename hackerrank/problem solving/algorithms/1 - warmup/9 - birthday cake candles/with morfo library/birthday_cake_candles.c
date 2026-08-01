// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

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
// T: O(n)
// S: O(1) extra space
int birthday_cake_candles(const int *candles, int n)
{
    int max = candles[0];
    int count = 1;

    for (int i = 1; i < n; ++i) {
        if (candles[i] > max) {
            max = candles[i];
            count = 1;
        } else if (candles[i] == max)
            ++count;
    }

    return count;
}
