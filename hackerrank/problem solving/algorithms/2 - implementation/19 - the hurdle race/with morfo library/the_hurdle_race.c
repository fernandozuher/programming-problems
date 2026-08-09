// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

int hurdle_race(const int *hurdles, size_t n, int max_jump);

int main()
{
    morfo_skip_input();
    int max_jump = morfo_read(int);
    size_t n;
    int *hurdles = morfo_readln(int, &n);

    printf("%d\n", hurdle_race(hurdles, n, max_jump));

    free(hurdles);
    return 0;
}

// n: length of hurdles
// T: O(n)
// S: O(1) extra space
int hurdle_race(const int *hurdles, size_t n, int max_jump)
{
    int highest = hurdles[0];
    for (size_t i = 1; i < n; ++i)
        highest = highest > hurdles[i] ? highest : hurdles[i];

    int max = highest - max_jump;
    return 0 > max ? 0 : max;
}
