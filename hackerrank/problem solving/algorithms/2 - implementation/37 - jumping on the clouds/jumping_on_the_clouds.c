// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int *arr, int n);
int minimum_number_of_jumps(const int *clouds, int n);
int next_jump(int index, const int *clouds, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int clouds[n];
    read_numbers(clouds, n);
    printf("%d\n", minimum_number_of_jumps(clouds, n));

    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

int minimum_number_of_jumps(const int *clouds, int n)
{
    int jumps = 0;
    for (int i = 0, size = n - 1; i < size; i += next_jump(i, clouds, n))
        ++jumps;
    return jumps;
}

int next_jump(int index, const int *clouds, int n)
{
    bool is_next_second_cloud_cumulus = false;
    if (index + 2 < n)
        is_next_second_cloud_cumulus = clouds[index + 2] == 0;
    return is_next_second_cloud_cumulus ? 2 : 1;
}
