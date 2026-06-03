// https://www.hackerrank.com/challenges/array-left-rotation/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_numbers(int *arr, int n);
int *rotate(const int *arr, int n, int rotate_by);

int main()
{
    int n, rotate_by;
    scanf("%d %d", &n, &rotate_by);
    int arr[n];
    read_numbers(arr, n);
    int *rotated = rotate(arr, n, rotate_by);
    for (int i = 0; i < n; ++i)
        printf("%d ", rotated[i]);

    free(rotated);

    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// T: O(n)
// S: O(n) extra space
int *rotate(const int *arr, int n, int rotate_by)
{
    if (rotate_by >= n)
        rotate_by %= n;
    auto rotated = (int *) malloc(n * sizeof(int));
    memmove(rotated, arr + rotate_by, (n - rotate_by) * sizeof(int));
    memmove(rotated + (n - rotate_by), arr, rotate_by * sizeof(int));
    return rotated;
}
