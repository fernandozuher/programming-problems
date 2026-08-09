// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

#define MAX_VALUE 99

void counter(const int *arr, size_t n, int *freq_map);
int picking_numbers(const int *freq_map);

int main()
{
    morfo_skip_input_ln();
    size_t n;
    int *arr = morfo_readln(int, &n);

    int freq_map[MAX_VALUE + 1] = {};
    counter(arr, n, freq_map);
    printf("%d\n", picking_numbers(freq_map));

    free(arr);
    return 0;
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
void counter(const int *arr, size_t n, int *freq_map)
{
    for (size_t i = 0; i < n; ++i)
        ++freq_map[arr[i]];
}

// k: length of freq_map
// 1 <= k <= 99
// T: O(k) = O(99) = O(1)
// S: O(1) extra space
int picking_numbers(const int *freq_map)
{
    int max_len = 0;
    for (int i = 1, n2 = MAX_VALUE + 1; i < n2; ++i) {
        if (!freq_map[i])
            continue;
        int current = freq_map[i] + freq_map[i + 1];
        max_len = max_len >= current ? max_len : current;
    }
    return max_len;
}
