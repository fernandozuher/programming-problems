// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int *arr, int n);
int min_deletions_to_equalize(const int *arr, int n);
void counter(const int *arr, int *counter_arr, int n);
int max(const int *arr, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    read_numbers(arr, n);
    printf("%d\n", min_deletions_to_equalize(arr, n));
    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n: length of arr, 1 <= n <= 100
// arr[i]: 1 <= arr[i] <= 100
// T: O(n) = O(101) = O(1)
// S: O(n) = O(101) = O(1) extra space
int min_deletions_to_equalize(const int *arr, int n)
{
    constexpr int max_n = 101;
    int counter_arr[max_n] = {}; // C23
    counter(arr, counter_arr, n);
    return n - max(counter_arr, max_n);
}

void counter(const int *arr, int *counter_arr, int n)
{
    for (int i = 0; i < n; ++i)
        ++counter_arr[arr[i]];
}

int max(const int *arr, int n)
{
    int max = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
