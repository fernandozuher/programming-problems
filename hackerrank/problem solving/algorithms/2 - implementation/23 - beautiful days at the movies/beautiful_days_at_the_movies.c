// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true
// C23

#include <stdio.h>

int beautiful_days(int start_day, int end_day, int divisor);
bool is_beautiful_day(int day, int divisor);
int reverse_number(int number);

int main()
{
    int start_day, end_day, divisor;
    scanf("%d %d %d", &start_day, &end_day, &divisor);
    printf("%d\n", beautiful_days(start_day, end_day, divisor));
    return 0;
}

// n: range (end_day - start_day + 1)
// d: number of digits of the largest day
// T: O(n * d)
// S: O(1) extra space
int beautiful_days(int start_day, int end_day, int divisor)
{
    int count = 0;
    for (int day = start_day; day <= end_day; ++day)
        count += is_beautiful_day(day, divisor);
    return count;
}

bool is_beautiful_day(int day, int divisor)
{
    return (day - reverse_number(day)) % divisor == 0;
}

int reverse_number(int number)
{
    int reversed_number = 0;
    for (; number > 0; number /= 10)
        reversed_number = reversed_number * 10 + number % 10;
    return reversed_number;
}
