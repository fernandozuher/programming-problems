// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>

#define TRANSITION_YEAR 1918
#define DATE_BUF_SIZE 12 // "dd.mm.yyyy" + '\0'

char *calculate_date_of_256th_day(int year);
bool is_leap_year(int year);
bool is_leap_julian_year(int year);
bool is_leap_gregorian_year(int year);

int main()
{
    int year;
    scanf("%d", &year);
    char *date = calculate_date_of_256th_day(year);
    puts(date);
    free(date);
    return 0;
}

char *calculate_date_of_256th_day(int year)
{
    int day;
    if (year == TRANSITION_YEAR)
        day = 26;
    else
        day = is_leap_year(year) ? 12 : 13;

    char *date = malloc(DATE_BUF_SIZE * sizeof(char));
    snprintf(date, DATE_BUF_SIZE, "%02d.09.%d", day, year);
    return date;
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
