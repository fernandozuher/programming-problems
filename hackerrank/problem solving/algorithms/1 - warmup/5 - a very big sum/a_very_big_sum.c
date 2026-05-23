// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

#include <stdio.h>

void read_numbers(long *arr, int n);
long a_very_big_sum(const long *arr, int n);

int main()
{
    int n;
    scanf("%d", &n);
    long arr[n];
    read_numbers(arr, n);
    printf("%ld\n", a_very_big_sum(arr, n));
    return 0;
}


void read_numbers(long *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%ld", &arr[i]);
}

// T: O(n)
// S: O(1) extra space
long a_very_big_sum(const long *arr, int n)
{
    long sum = 0;
    for (int i = 0; i < n; ++i)
        sum += arr[i];
    return sum;
}
