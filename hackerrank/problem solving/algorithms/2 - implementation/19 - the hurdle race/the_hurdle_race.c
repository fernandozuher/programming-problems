// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

#include <stdio.h>

void read_numbers(int numbers[], int n);
int hurdle_race(const int hurdles[], int n, int max_jump);

int main()
{
    int n, max_jump;
    scanf("%d %d", &n, &max_jump);

    int hurdles[n];
    read_numbers(hurdles, n);
    printf("%d\n", hurdle_race(hurdles, n, max_jump));

    return 0;
}

void read_numbers(int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
}

int hurdle_race(const int hurdles[], int n, int max_jump)
{
    int highest = hurdles[0];
    for (int i = 1; i < n; ++i)
        if (highest < hurdles[i])
            highest = hurdles[i];

    int max = highest - max_jump;
    return 0 > max ? 0 : max;
}
