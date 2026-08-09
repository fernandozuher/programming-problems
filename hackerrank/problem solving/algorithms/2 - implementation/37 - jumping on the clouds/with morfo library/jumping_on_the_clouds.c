// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

int min_jumps(const int *clouds, int n);
int skip(int idx, const int *clouds, int n);
bool is_next_second_cloud_cumulus(int idx, const int *clouds, int n);

int main()
{
    morfo_skip_input_ln();
    size_t n;
    int *clouds = morfo_readln(int, &n);
    printf("%d\n", min_jumps(clouds, (int)n));
    free(clouds);
    return 0;
}

// n: length of clouds
// T: O(n)
// S: O(1) extra space
int min_jumps(const int *clouds, int n)
{
    int jumps = 0;
    for (int i = 0, size = n - 1; i < size; i += skip(i, clouds, n))
        ++jumps;
    return jumps;
}

int skip(int idx, const int *clouds, int n)
{
    return is_next_second_cloud_cumulus(idx, clouds, n) ? 2 : 1;
}

bool is_next_second_cloud_cumulus(int idx, const int *clouds, int n)
{
    return idx + 2 < n && clouds[idx + 2] == 0;
}
