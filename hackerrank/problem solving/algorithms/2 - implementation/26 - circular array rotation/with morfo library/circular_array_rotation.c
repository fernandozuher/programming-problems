// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

#include <stdio.h>
#include "morfo/io.h"

void print_queries(const int *arr, int n, int n_rotation, int n_queries);

int main()
{
    int n, n_rotation, n_queries;
    morfo_read_many(&n, &n_rotation, &n_queries);
    int arr[n];
    morfo_read_n(arr, n);
    print_queries(arr, n, n_rotation, n_queries);
    return 0;
}

// T: O(n_queries)
// S: O(1) extra space
void print_queries(const int *arr, int n, int n_rotation, int n_queries)
{
    int offset = n - n_rotation % n;
    for (int i = 0; i < n_queries; ++i) {
        int query = morfo_read(int);
        int idx = (query + offset) % n;
        printf("%d\n", arr[idx]);
    }
}
