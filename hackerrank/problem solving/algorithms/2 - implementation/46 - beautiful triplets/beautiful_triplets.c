// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>

void read_numbers(int *arr, int n);
int find_beautiful_triplets(const int *arr, int n, int beautiful_difference);
int compare(const void *a, const void *b);

int main()
{
    int n, beautiful_difference;
    scanf("%d %d", &n, &beautiful_difference);
    int arr[n];
    read_numbers(arr, n);
    printf("%d\n", find_beautiful_triplets(arr, n, beautiful_difference));
    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n: length of array arr
// T: O(n)
// S: O(n) extra space
int find_beautiful_triplets(const int *arr, int n, int beautiful_difference)
{
    int count = 0;

    for (int i = 0, double_bd = 2 * beautiful_difference, n1 = n - 2; i < n1; ++i) {
        int first = arr[i] + beautiful_difference;
        int second = arr[i] + double_bd;

        void *found_first = bsearch(&first, arr + i + 1, n - i - 1, sizeof(int), compare);
        if (found_first) {
            int found_index = ((int *) found_first) - arr;
            auto found_second = bsearch(&second, arr + found_index + 1, n - found_index - 1, sizeof(int), compare);
            count += found_second ? 1 : 0;
        }
    }

    return count;
}

int compare(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}
