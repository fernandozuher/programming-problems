// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_nums(long *arr, int n);
void calc_min_max_sum(const long *arr, int n, long *min_max_sum);

int main()
{
    constexpr int n = 5;
    long arr[n];
    read_nums(arr, n);

    long min_max_sum[2];
    calc_min_max_sum(arr, n, min_max_sum);
    printf("%ld %ld\n", min_max_sum[0], min_max_sum[1]);

    return 0;
}

void read_nums(long *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%ld", &arr[i]);
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
void calc_min_max_sum(const long *arr, int n, long *min_max_sum)
{
    long total, min_value, max_value;
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
