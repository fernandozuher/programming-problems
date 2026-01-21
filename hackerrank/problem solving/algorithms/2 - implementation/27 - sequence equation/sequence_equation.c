// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

#include <stdio.h>

void read_numbers(int *arr, int n);
void sequence_equation(const int *arr, int *res, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    read_numbers(arr, n);

    int res[n];
    sequence_equation(arr, res, n);
    for (int i = 0; i < n; ++i)
        printf("%d\n", res[i]);

    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n: length of array arr/output
// T: O(n)
// S: O(n) extra space
void sequence_equation(const int *arr, int *res, int n)
{
    int values_to_index[n];
    for (int i = 0; i < n; ++i)
        values_to_index[arr[i] - 1] = i;

    for (int i = 0; i < n; ++i)
        res[i] = values_to_index[values_to_index[i]] + 1;
}
