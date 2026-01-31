// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int *arr, int n);
int min_jumps(const int *clouds, int n);
int skip(int idx, const int *clouds, int n);
bool is_next_second_cloud_cumulus(int idx, const int *clouds, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int clouds[n];
    read_numbers(clouds, n);
    printf("%d\n", min_jumps(clouds, n));
    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n: length of array clouds
// T: O(n)
// S: O(1) extra space
int min_jumps(const int *clouds, int n)
{
    int jumps = 0;
    for (int i = 0, size = n - 1; i < size; i += skip(i, clouds, n), ++jumps);
    return jumps;
}

int skip(int idx, const int *clouds, int n)
{
    return is_next_second_cloud_cumulus(idx, clouds, n) ? 2 : 1;
}

bool is_next_second_cloud_cumulus(int idx, const int *clouds, int n)
{
    return idx + 2 < n && clouds[idx + 2] == 0;
}
