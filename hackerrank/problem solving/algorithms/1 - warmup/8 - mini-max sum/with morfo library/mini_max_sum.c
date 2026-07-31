// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

void calc_min_max_sum(const long long *arr, int n, long long *min_max_sum);

int main()
{
    size_t n;
    long long *arr = morfo_readln(long long, &n);

    long long min_max_sum[2];
    calc_min_max_sum(arr, (int)n, min_max_sum);
    printf("%lld %lld\n", min_max_sum[0], min_max_sum[1]);

    free(arr);

    return 0;
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
void calc_min_max_sum(const long long *arr, int n, long long *min_max_sum)
{
    long long total, min_value, max_value;
    total = min_value = max_value = arr[0];

    for (int i = 1; i < n; ++i) {
        total += arr[i];
        if (arr[i] < min_value)
            min_value = arr[i];
        if (arr[i] > max_value)
            max_value = arr[i];
    }

    min_max_sum[0] = total - max_value;
    min_max_sum[1] = total - min_value;
}
