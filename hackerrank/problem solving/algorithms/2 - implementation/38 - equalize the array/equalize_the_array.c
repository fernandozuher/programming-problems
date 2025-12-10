// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

void read_numbers(int *arr, int n);
int cmp(const void *a, const void *b);
int equalize_array(const int *arr, int n);
int max_count(const int *arr, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    read_numbers(arr, n);
    qsort(arr, n, sizeof(int), cmp);

    printf("%d\n", equalize_array(arr, n));

    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

int cmp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int equalize_array(const int *arr, int n)
{
    return n - max_count(arr, n);
}

int max_count(const int *arr, int n)
{
    int max_count = 1;

    for (int i = 1, temp_max = 1; i < n; ++i)
        if (arr[i - 1] == arr[i]) {
            ++temp_max;
            if (temp_max > max_count)
                max_count = temp_max;
        } else
            temp_max = 1;

    return max_count;
}
