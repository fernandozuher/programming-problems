// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/collections.h"
#include "morfo/io.h"

void calc_min_max_sum(const long long *arr, int n, long long *min_max_sum);
long long add(long long a, long long b);
long long smaller(long long a, long long b);
long long larger(long long a, long long b);

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

// T: O(n)
// S: O(1) extra space
void calc_min_max_sum(const long long *arr, int n, long long *min_max_sum)
{
    long long total = 0;
    long long min_value = arr[0], max_value = arr[0];

    morfo_reduce_many(
        arr, n,
        add, &total,
        smaller, &min_value,
        larger, &max_value
    );

    min_max_sum[0] = total - max_value;
    min_max_sum[1] = total - min_value;
}

long long add(long long a, long long b)
{
    return a + b;
}

long long smaller(long long a, long long b)
{
    return b < a ? b : a;
}

long long larger(long long a, long long b)
{
    return b > a ? b : a;
}
