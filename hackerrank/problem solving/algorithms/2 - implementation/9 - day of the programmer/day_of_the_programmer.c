// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true
// C23

#include <stdio.h>

#define TRANSITION_YEAR 1918

void calc_date_of_256th_day(int year, char *date, size_t n);
bool is_leap_year(int year);
bool is_leap_julian_year(int year);
bool is_leap_gregorian_year(int year);

int main()
{
    int year;
    scanf("%d", &year);

    constexpr size_t n = 11; // "dd.mm.yyyy" + '\0'
    char date[n];

    calc_date_of_256th_day(year, date, n);
    printf("%s", date);

    return 0;
}

// T: O(1)
// S: O(1) extra space
void calc_date_of_256th_day(int year, char *date, size_t n)
{
    int day;
    if (year == TRANSITION_YEAR)
        day = 26;
    else
        day = is_leap_year(year) ? 12 : 13;

    snprintf(date, n, "%02d.09.%d", day, year);
}

bool is_leap_year(int year)
{
    if (year < TRANSITION_YEAR)
        return is_leap_julian_year(year);
    if (year > TRANSITION_YEAR)
        return is_leap_gregorian_year(year);
    return false;
}

bool is_leap_julian_year(int year)
{
    return year % 4 == 0;
}

bool is_leap_gregorian_year(int year)
{
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}
