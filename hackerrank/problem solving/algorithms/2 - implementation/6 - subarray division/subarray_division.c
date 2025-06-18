// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true
// C23

#include <stdio.h>

void read_numbers(int numbers[], int n);
int birthday(const int chocolate_squares[], int n, const int day_month[]);

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

void read_numbers(int numbers[], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &numbers[i]);
}

int birthday(const int chocolate_squares[], int n, const int day_month[])
{
    int day = day_month[0];
    int month = day_month[1];

    if (month > n)
        return 0;

    int sum = 0;
    for (int i = 0; i < month; ++i)
        sum += chocolate_squares[i];

    int ways_bar_can_be_divided = sum == day;

    for (int i = month; i < n; ++i) {
        sum += chocolate_squares[i] - chocolate_squares[i - month];
        if (sum == day)
            ++ways_bar_can_be_divided;
    }

    return ways_bar_can_be_divided;
}
