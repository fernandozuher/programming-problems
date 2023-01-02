// Source: https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* read_line_as_int_array(const int n);
char* day_of_programmer(const int year);
    bool is_leap_gregorian_year(const int n);
    bool is_leap_julian_year(const int n);

int main() {
    const int *year = read_line_as_int_array(1);

    const char *result = day_of_programmer(year[0]);
    printf("%s", result);

    return 0;
}

    int* read_line_as_int_array(const int n) {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &array[i]);
        return array;
    }

    char* day_of_programmer(const int year) {
        char *date = (char*) calloc(11, sizeof(char));

        if (year != 1918) {
            bool is_leap = year > 1918 ? is_leap_gregorian_year(year) : is_leap_julian_year(year);
            is_leap ? strcpy(date, "12.09.") : strcpy(date, "13.09.");
        }
        else
            strcpy(date, "26.09.");

        char str[5];
        sprintf(str, "%d", year);
        strcpy(date+6, str);
        
        return date;
    }

        bool is_leap_gregorian_year(const int year) {
            return !(year % 400) || (!(year % 4) && year % 100);
        }

        bool is_leap_julian_year(const int year) {
            return !(year % 4);
        }
