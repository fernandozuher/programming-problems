// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_24_hour_time(const char *hour_12);
char *gen_new_hour(char day_period, const char *hour);

int main()
{
    constexpr int max_string = 10;
    char string[max_string + 1]; // + 1 = \0
    scanf("%10s", string);

    char *hour_24 = to_24_hour_time(string);
    puts(hour_24);

    free(hour_24);

    return 0;
}

// T: O(1)
// S: O(1) extra space
char *to_24_hour_time(const char *hour_12)
{
    constexpr int hour_24_size = 8;
    auto hour_24 = (char *) malloc(hour_24_size + 1); // + 1 = \0
    strncpy(hour_24, hour_12, hour_24_size);
    hour_24[hour_24_size] = '\0';

    constexpr int hour_size = 2;
    char hour[hour_size + 1]; // + 1 = \0
    strncpy(hour, hour_12, hour_size);
    hour[hour_size] = '\0';

    constexpr int day_period_index = 8;
    char day_period = hour_12[day_period_index];

    if ((!strcmp(hour, "12") && day_period == 'A')
        ||
        (strcmp(hour, "12") && day_period == 'P')) {
        auto new_hour = gen_new_hour(day_period, hour);
        memcpy(hour_24, new_hour, hour_size);
        free(new_hour);
    }

    return hour_24;
}

char *gen_new_hour(char day_period, const char *hour)
{
    constexpr int hour_size = 2;
    auto new_hour = (char *) malloc(hour_size + 1); // + 1 = \0

    if (day_period == 'A')
        memcpy(new_hour, "00", hour_size);
    else {
        int parsed_hour = atoi(hour);
        parsed_hour += 12;
        sprintf(new_hour, "%02d", parsed_hour);
    }

    return new_hour;
}
