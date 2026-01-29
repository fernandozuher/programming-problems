// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

void read_numbers(int *arr, int n);
int compare_function(const void *a, const void *b);
void cut_the_sticks(const int *arr, int n, int *res, int *n2);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    read_numbers(arr, n);
    qsort(arr, n, sizeof(int), compare_function);

    int n2 = 0;
    int res[n];
    cut_the_sticks(arr, n, res, &n2);

    for (int i = 0; i < n2; ++i)
        printf("%d\n", res[i]);

    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

int compare_function(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

// n: length of arr
// k: number of distinct values in arr
// T: O(n)
//    Sorting arr before calling this function is O(n log n)
// S: O(k), but O(n) in the worst case extra space
//    Sorting arr before calling this function is O(n) extra space
void cut_the_sticks(const int *arr, int n, int *res, int *n2)
{
    int slow = 0;
    for (int fast = 0; fast < n; ++fast) {
        if (arr[slow] == arr[fast])
            continue;
        res[(*n2)++] = n - slow;
        slow = fast;
    }
    res[(*n2)++] = n - slow;
}
