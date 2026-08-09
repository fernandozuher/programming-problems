// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

int find_beautiful_triplets(const int *arr, int n, int beautiful_difference);
int compare(const void *a, const void *b);

int main()
{
    morfo_skip_input();
    int beautiful_difference = morfo_read(int);
    size_t n;
    int *arr = morfo_readln(int, &n);
    printf("%d\n", find_beautiful_triplets(arr, (int)n, beautiful_difference));
    free(arr);
    return 0;
}

// n: length of arr
// T: O(n log n)
// S: O(1) extra space
int find_beautiful_triplets(const int *arr, int n, int beautiful_difference)
{
    int count = 0;

    for (int i = 0, double_bd = 2 * beautiful_difference, n1 = n - 2; i < n1; ++i) {
        int first = arr[i] + beautiful_difference;
        int second = arr[i] + double_bd;

        void *found_first = bsearch(&first, arr + i + 1, n - i - 1, sizeof(int), compare);
        if (found_first) {
            int found_index = (int *) found_first - arr;
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
