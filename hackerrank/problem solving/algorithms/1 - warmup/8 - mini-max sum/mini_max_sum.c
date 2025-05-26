// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(long numbers[], int n);
void calc_min_max_sum(const long numbers[], int n, long min_max_sum[]);

int main()
{
    constexpr int n = 5;
    long numbers[n];
    read_numbers(numbers, n);

    long min_max_sum[2];
    calc_min_max_sum(numbers, n, min_max_sum);
    printf("%ld %ld\n", min_max_sum[0], min_max_sum[1]);

    return 0;
}

void read_numbers(long numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%ld", &numbers[i]);
}

void calc_min_max_sum(const long numbers[], int n, long min_max_sum[])
{
    long sum, min, max;
    sum = min = max = numbers[0];

    for (int i = 1; i < n; ++i) {
        sum += numbers[i];
        if (numbers[i] < min)
            min = numbers[i];
        if (numbers[i] > max)
            max = numbers[i];
    }

    min_max_sum[0] = sum - max;
    min_max_sum[1] = sum - min;
}
