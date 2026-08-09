// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

int birthday(const int *chocolate_squares, int n, const int *day_month);

int main()
{
    int n = morfo_read(int);
    int *chocolate_squares = morfo_read_n_alloc(int, n);

    constexpr int n_day_month = 2;
    int day_month[n_day_month];
    morfo_read_n(day_month, n_day_month);

    printf("%d\n", birthday(chocolate_squares, n, day_month));

    free(chocolate_squares);
    return 0;
}

// n: length of chocolate_squares
// 1 <= n <= 100
// T: O(n) = O(100) = O(1)
// S: O(1) extra space
int birthday(const int *chocolate_squares, int n, const int *day_month)
{
    int day = day_month[0];
    int month = day_month[1];

    if (month > n)
        return 0;

    int sum = 0;
    for (int i = 0; i < month; ++i)
        sum += chocolate_squares[i];

    int count = sum == day;

    for (int i = month; i < n; ++i) {
        sum += chocolate_squares[i] - chocolate_squares[i - month];
        count += sum == day;
    }

    return count;
}
