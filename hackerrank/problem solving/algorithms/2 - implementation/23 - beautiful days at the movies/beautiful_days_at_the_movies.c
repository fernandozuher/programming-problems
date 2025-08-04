// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true
// C23

#include <math.h>
#include <stdio.h>

int beautiful_days(int startDay, int endDay, int divisor);
bool is_day_beautiful(int day, int divisor);
int reverse_number(int number);

int main()
{
    int startDay, endDay, divisor;
    scanf("%d %d %d", &startDay, &endDay, &divisor);
    printf("%d\n", beautiful_days(startDay, endDay, divisor));
    return 0;
}

int beautiful_days(int startDay, int endDay, int divisor)
{
    int count = 0;
    for (int day = startDay; day <= endDay; ++day)
        count += is_day_beautiful(day, divisor);
    return count;
}

bool is_day_beautiful(int day, int divisor)
{
    return abs(day - reverse_number(day)) % divisor == 0;
}

int reverse_number(int number)
{
    int reversed_number = 0;
    for (; number > 0; number = number / 10)
        reversed_number = (reversed_number * 10) + (number % 10);
    return reversed_number;
}
