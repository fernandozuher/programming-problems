// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int *arr, int n);
int birthday(const int *chocolate_squares, int n, const int *day_month);

int main()
{
    int n;
    scanf("%d", &n);
    int chocolate_squares[n];
    read_numbers(chocolate_squares, n);

    constexpr int n_day_month = 2;
    int day_month[n_day_month];
    read_numbers(day_month, n_day_month);

    printf("%d\n", birthday(chocolate_squares, n, day_month));

    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n: length of array chocolate_squares
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
