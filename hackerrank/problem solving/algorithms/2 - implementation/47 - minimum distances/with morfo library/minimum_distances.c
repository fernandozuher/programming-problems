// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

int min_distance(const int *arr, int n);

int main()
{
    morfo_skip_input_ln();
    size_t n;
    int *arr = morfo_readln(int, &n);
    printf("%d\n", min_distance(arr, (int)n));
    free(arr);
    return 0;
}

// 1 <= arr[i] <= 10^5
// n: length of arr, 1 <= n <= 10^3
// T: O(100000 + n) = O(100000 + 1000) = O(1)
// S: O(100000) = O(1) extra space
int min_distance(const int *arr, int n)
{
    constexpr int limit = 100000;
    int last_seen[limit];
    for (int i = 0; i < limit; ++i)
        last_seen[i] = -1;

    int min_dist = -1;

    for (int i = 0; i < n; ++i) {
        int x = arr[i];

        if (last_seen[x] != -1) {
            int dist = i - last_seen[x];

            if (min_dist == -1 || dist < min_dist) {
                min_dist = dist;
                if (min_dist == 1) {
                    return 1;
                }
            }
        }

        last_seen[x] = i;
    }

    return min_dist;
}
