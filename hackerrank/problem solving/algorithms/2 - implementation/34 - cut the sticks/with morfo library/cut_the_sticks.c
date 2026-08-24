// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include "morfo/collections.h"
#include "morfo/io.h"

void cut_the_sticks(const int *arr, int n, int *res, int *n2);

int main()
{
    morfo_skip_input_ln();
    size_t n;
    int *arr = morfo_readln(int, &n);
    morfo_sort(arr, n);

    int n2 = 0;
    int res[n];
    cut_the_sticks(arr, (int)n, res, &n2);

    morfo_println(res, n2);

    free(arr);
    return 0;
}

// n: length of arr
// k: number of distinct values in arr
// k <= n
// T: O(n)
//    Sorting arr beforehand is O(n log n)
// S: O(k) = O(n) extra space
//    Sorting arr beforehand is O(n) extra space
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
