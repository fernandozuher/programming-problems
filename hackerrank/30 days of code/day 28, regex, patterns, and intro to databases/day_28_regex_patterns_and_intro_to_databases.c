#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

int sortstring(const void *str1, const void *str2) {
    char *const *pp1 = str1;
    char *const *pp2 = str2;
    return strcmp(*pp1, *pp2);
}

void sortutil(char* lines[], int count) {
    qsort(lines, count, sizeof(*lines), sortstring);
}

int main()
{
    int N = parse_int(ltrim(rtrim(readline())));
    char* first_names[N];
    int N2 = 0;

    for (int N_itr = 0; N_itr < N; N_itr++) {
        char** first_multiple_input = split_string(rtrim(readline()));
        char* firstName = *(first_multiple_input + 0);
        char* emailID = *(first_multiple_input + 1);

        int index_arroba;
        for (index_arroba = 0; emailID[index_arroba]!= '@'; ++index_arroba);
        int is_gmail_domain = strcmp(&emailID[index_arroba], "@gmail.com");

        if (is_gmail_domain == 0)
            first_names[N2++] = firstName;
    }

    sortutil(first_names, N2);
    for (int i = 0; i < N2; ++i)
        puts(first_names[i]);

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

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
