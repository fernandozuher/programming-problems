// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

#include <stdio.h>

void read_numbers(int numbers[], int n);
int birthday_cake_candles(int candles[], int n);
int max_element(const int numbers[], int n);
int count(const int numbers[], int n, int element);

int main()
{
    int n;
    scanf("%d", &n);
    int candles[n];
    read_numbers(candles, n);
    printf("%d\n", birthday_cake_candles(candles, n));
    return 0;
}

void read_numbers(int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
}

int birthday_cake_candles(int candles[], int n)
{
    return count(candles, n, max_element(candles, n));
}

int max_element(const int numbers[], int n)
{
    int max = numbers[0];
    while (n--)
        if (numbers[n] > max)
            max = numbers[n];
    return max;
}

int count(const int numbers[], int n, int element)
{
    int count = 0;
    while (n--)
        if (numbers[n] == element)
            ++count;
    return count;
}
