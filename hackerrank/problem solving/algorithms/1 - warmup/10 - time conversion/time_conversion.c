#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* timeConversion(char* time) {
    char *converted_time = (char*) calloc(9, sizeof(char));
    char hour_string[3];
    char period_of_day[2];

    strncpy(converted_time, time, 8);
    converted_time[8] = '\0';
    
    strncpy(hour_string, time, 2);
    hour_string[2] = '\0';
    
    strncpy(period_of_day, time+8, 1);
    period_of_day[1] = '\0';

    if (strcmp(hour_string, "12") == 0) {
        if (strcmp(period_of_day, "A") == 0)
            strncpy(converted_time, "00", 2);
    }
    else if (strcmp(period_of_day, "P") == 0) {
        int hour = atoi(hour_string);
        hour += 12;

        char hour_string[3];
        sprintf(hour_string, "%d", hour);
        strncpy(converted_time, hour_string, 2);
    }
    return converted_time;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
