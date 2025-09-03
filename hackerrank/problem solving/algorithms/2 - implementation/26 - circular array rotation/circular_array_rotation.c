// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

#include <stdio.h>

void read_numbers(int *arr, int n);
void print_queries(const int *arr, const int *queries, int n, int n_queries, int n_rotation);

int main()
{
    int n, n_rotation, n_queries;
    scanf("%d %d %d", &n, &n_rotation, &n_queries);
    int arr[n], queries[n_queries];
    read_numbers(arr, n);
    read_numbers(queries, n_queries);
    print_queries(arr, queries, n, n_queries, n_rotation);
    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

void print_queries(const int *arr, const int *queries, int n, int n_queries, int n_rotation)
{
    int r = n_rotation % n;
    for (int i = 0; i < n_queries; ++i) {
        int idx = (queries[i] + n - r) % n;
        printf("%d\n", arr[idx]);
    }
}
