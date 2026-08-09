// https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

int jumping_on_the_clouds(const int *clouds, int n, int jump_length);

int main()
{
    morfo_skip_input();
    int jump_length = morfo_read(int);
    size_t n;
    int *arr = morfo_readln(int, &n);
    printf("%d\n", jumping_on_the_clouds(arr, (int)n, jump_length));
    free(arr);
    return 0;
}

// n: length of clouds; 2 to 25
// k (jump_length): 1 <= k <= n
// n % k = 0
// c[i] = 0 or 1
// T: O(n) = O(25) = O(1)
// S: O(1) extra space
int jumping_on_the_clouds(const int *clouds, int n, int jump_length)
{
    int energy = 100;

    for (int cloud_index = 0;;) {
        energy -= clouds[cloud_index] ? 3 : 1;
        cloud_index = (cloud_index + jump_length) % n;
        if (!cloud_index)
            break;
    }

    return energy;
}
