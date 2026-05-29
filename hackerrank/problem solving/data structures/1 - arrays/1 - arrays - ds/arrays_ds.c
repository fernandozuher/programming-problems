// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

#include <stdio.h>

void reverse(int *arr, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);

    reverse(arr, n);
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);

    return 0;
}

// T: O(n/2) = O(n)
// S: O(1) extra space
void reverse(int *arr, int n)
{
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
