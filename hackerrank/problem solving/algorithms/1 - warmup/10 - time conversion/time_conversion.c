// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* time_conversion(const char *time);
char* convert_time(const char *time);
char* get_hour(const char *time);
char* get_day_period(const char* time);
bool is_12_hour(const char *hour);
bool is_first_period_of_day(const char *day_period);
char* change_hour(const char *hour, char *converted_time);
char* convert_pm_hour_to_24_h(char *hour);

int main()
{
    const int max_string = 15;
    char input[max_string];
    scanf("%s", input);
    printf("%s\n", time_conversion(input));

    return 0;
}

    char* time_conversion(const char *time)
    {
        char *converted_time = convert_time(time);
        char *hour = get_hour(time);
        char *day_period = get_day_period(time);

        if (is_12_hour(hour)) {
            if (is_first_period_of_day(day_period)) {
                char *new_hour = "00";
                converted_time = change_hour(new_hour, converted_time);
            }
        }
        else if (!is_first_period_of_day(day_period)) {
            char *new_hour = convert_pm_hour_to_24_h(hour);
            converted_time = change_hour(new_hour, converted_time);
        }

        return converted_time;
    }

        char* convert_time(const char *time)
        {
            const int time_string_size = 9;
            char *converted_time = (char*) calloc(time_string_size, sizeof(char));
            strncpy(converted_time, time, time_string_size - 1);
            converted_time[8] = '\0';
            return converted_time;
        }

        char* get_hour(const char *time)
        {
            const int hour_size = 3;
            char *hour = (char*) calloc(hour_size, sizeof(char));
            strncpy(hour, time, hour_size);
            hour[2] = '\0';
            return hour;
        }

        char* get_day_period(const char *time)
        {
            const int day_period_string_size = 2;
            char *day_period = (char*) calloc(day_period_string_size, sizeof(char));

            const int time_string_size = 8;
            strncpy(day_period, time + time_string_size, 1);
            day_period[1] = '\0';

            return day_period;
        }

        bool is_12_hour(const char *hour)
        {
            return !strcmp(hour, "12");
        }

        bool is_first_period_of_day(const char *day_period)
        {
            return !strcmp(day_period, "A");
        }

        char* change_hour(const char *hour, char *time)
        {
            const int hour_size = 2;
            strncpy(time, hour, hour_size);
            return time;
        }

        char* convert_pm_hour_to_24_h(char *hour)
        {
            int new_hour = atoi(hour);
            new_hour += 12;
            sprintf(hour, "%d", new_hour);
            return hour;
        }
