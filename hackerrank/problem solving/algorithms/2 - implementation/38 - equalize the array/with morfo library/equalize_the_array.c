// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

int min_deletions_to_equalize(const int *arr, int n);
void counter(const int *arr, int *freq_map, int n);
int max(const int *arr, int n);

int main()
{
    morfo_skip_input_ln();
    size_t n;
    int *arr = morfo_readln(int, &n);
    printf("%d\n", min_deletions_to_equalize(arr, (int)n));
    free(arr);
    return 0;
}

// n: length of arr, 1 <= n <= 100
// arr[i]: 1 <= arr[i] <= 100
// T: O(n) = O(101) = O(1)
// S: O(n) = O(101) = O(1) extra space
int min_deletions_to_equalize(const int *arr, int n)
{
    constexpr int max_n = 101;
    int freq_map[max_n] = {};
    counter(arr, freq_map, n);
    return n - max(freq_map, max_n);
}

void counter(const int *arr, int *freq_map, int n)
{
    for (int i = 0; i < n; ++i)
        ++freq_map[arr[i]];
}

int max(const int *arr, int n)
{
    int max = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
