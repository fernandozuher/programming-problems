// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true
// From C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRANSITION_YEAR 1918

char *calculate_date_of_256th_day(int year);
    bool is_leap_year(int year);
        bool is_leap_gregorian_year(int year);
        bool is_leap_julian_year(int year);
    char *add_year_to_date(int year, char date[]);

int main()
{
    int year;
    scanf("%d", &year);
    char *date = calculate_date_of_256th_day(year);
    puts(date);
    free(date);
    return 0;
}

    char *calculate_date_of_256th_day(const int year)
    {
        constexpr int date_size = 11;
        auto date = (char*) malloc(date_size * sizeof(char));

        if (year != TRANSITION_YEAR)
            is_leap_year(year) ? strcpy(date, "12.09.") : strcpy(date, "13.09.");
        else
            strcpy(date, "26.09.");

        date = add_year_to_date(year, date);
        return date;
    }

        bool is_leap_year(const int year)
        {
            return year > TRANSITION_YEAR ? is_leap_gregorian_year(year) : is_leap_julian_year(year);
        }

            bool is_leap_gregorian_year(const int year)
            {
                return !(year % 400) || (!(year % 4) && year % 100);
            }

            bool is_leap_julian_year(const int year)
            {
                return !(year % 4);
            }

        char *add_year_to_date(const int year, char date[])
        {
            constexpr int year_size = 5;
            char str[year_size];
            sprintf(str, "%d", year);
            strcpy(date + 6, str);
            return date;
        }
