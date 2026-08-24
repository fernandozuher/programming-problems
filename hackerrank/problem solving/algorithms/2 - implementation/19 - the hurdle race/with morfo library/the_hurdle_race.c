// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"
#include "morfo/math.h"

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
    return morfo_max_of(0, morfo_max(hurdles, n) - max_jump);
}
