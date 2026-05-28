// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

#include <stdio.h>

void read_numbers(int *arr, int n);
int birthday_cake_candles(const int *candles, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int candles[n];
    read_numbers(candles, n);
    printf("%d\n", birthday_cake_candles(candles, n));
    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n: length of candles
// T: O(n)
// S: O(1) extra space
int birthday_cake_candles(const int *candles, int n)
{
    int max = candles[0];
    int count = 1;

    for (int i = 1; i < n; ++i) {
        if (candles[i] > max) {
            max = candles[i];
            count = 1;
        } else if (candles[i] == max)
            ++count;
    }

    return count;
}
