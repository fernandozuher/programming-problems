// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

#include <stdio.h>

void read_numbers(int *arr, int n);
void print_queries(const int *arr, int n, int n_rotation, int n_queries);

int main()
{
    int n, n_rotation, n_queries;
    scanf("%d %d %d", &n, &n_rotation, &n_queries);
    int arr[n];
    read_numbers(arr, n);
    print_queries(arr, n, n_rotation, n_queries);
    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

void print_queries(const int *arr, int n, int n_rotation, int n_queries)
{
    int r = n_rotation % n;
    for (int i = 0; i < n_queries; ++i) {
        int query;
        scanf("%d", &query);
        int idx = (query + n - r) % n;
        printf("%d\n", arr[idx]);
    }
}
