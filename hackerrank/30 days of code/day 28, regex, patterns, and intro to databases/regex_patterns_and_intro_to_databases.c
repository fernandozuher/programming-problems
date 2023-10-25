// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_gmail_domain(const char *email_id);
int compare_func(const void *str1, const void *str2);

int main()
{
    int n;
    scanf("%d", &n);

    char *first_names[n];
    int n2 = 0;
    const int max_string_size = 100;

    for (int i = 0; i < n; ++i) {
        char *first_name = (char*) calloc(max_string_size, sizeof(char));
        char *email_id = (char*) calloc(max_string_size, sizeof(char));
        scanf("%s %s", first_name, email_id);

        if (is_gmail_domain(email_id))
            first_names[n2++] = first_name;
    }

    qsort(first_names, n2, sizeof(*first_names), compare_func);
    for (int i = 0; i < n2; puts(first_names[i++]));

    return 0;
}

    bool is_gmail_domain(const char *email_id)
    {
        int index_arroba;
        for (index_arroba = 0; email_id[index_arroba] != '@'; ++index_arroba);
        return !strcmp(&email_id[index_arroba], "@gmail.com");
    }

    int compare_func(const void *str1, const void *str2)
    {
        const char *const *pp1 = str1;
        const char *const *pp2 = str2;
        return strcmp(*pp1, *pp2);
    }
