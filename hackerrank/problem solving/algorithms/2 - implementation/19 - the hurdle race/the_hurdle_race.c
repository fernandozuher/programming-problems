// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

#include <stdio.h>

void read_numbers(int *arr, size_t n);
int hurdle_race(const int *hurdles, size_t n, int max_jump);

int main()
{
    int n, max_jump;
    scanf("%d %d", &n, &max_jump);
    int hurdles[n];
    read_numbers(hurdles, n);

    printf("%d\n", hurdle_race(hurdles, n, max_jump));

    return 0;
}

void read_numbers(int *arr, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n: length of hurdles
// T: O(n)
// S: O(1) extra space
int hurdle_race(const int *hurdles, size_t n, int max_jump)
{
    int highest = hurdles[0];
    for (size_t i = 1; i < n; ++i)
        highest = highest > hurdles[i] ? highest : hurdles[i];

    int max = highest - max_jump;
    return 0 > max ? 0 : max;
}
