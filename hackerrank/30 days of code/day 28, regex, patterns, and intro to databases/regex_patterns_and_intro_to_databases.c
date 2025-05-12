// https://www.hackerrank.com/challenges/30-regex-patterns/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 101

typedef struct {
    char **array;
    int size;
} string_array;

string_array collect_gmail_users(int n);
char *collect_name_if_has_gmail_domain();
bool has_gmail_domain(const char *email);
void sort(string_array names);
int compare_func(const void *a, const void *b);
void print(string_array names);
void free_strings(string_array names);

int main()
{
    int n;
    scanf("%d", &n);
    string_array names = collect_gmail_users(n);
    sort(names);
    print(names);
    free_strings(names);
    return 0;
}

string_array collect_gmail_users(int n)
{
    auto names = (char **) malloc(n * sizeof(char *));
    int size = 0;

    for (int i = 0; i < n; ++i) {
        char *name = collect_name_if_has_gmail_domain();
        if (name)
            names[size++] = name;
    }

    names = realloc(names, size * sizeof(char *));
    string_array strings = {names, size};
    return strings;
}

char *collect_name_if_has_gmail_domain()
{
    auto name = (char *) malloc(MAX_STRING_LEN * sizeof(char));
    char email[MAX_STRING_LEN];
    scanf("%100s %100s", name, email);

    if (has_gmail_domain(email))
        return name;
    free(name);
    return nullptr;
}

bool has_gmail_domain(const char *email)
{
    const char *domain = "@gmail.com";
    size_t email_len = strlen(email);
    size_t domain_len = strlen(domain);
    return email_len >= domain_len && strcmp(email + (email_len - domain_len), domain) == 0;
}

void sort(string_array names)
{
    qsort(names.array, names.size, sizeof(*names.array), compare_func);
}

int compare_func(const void *a, const void *b)
{
    const char *const *pp1 = a;
    const char *const *pp2 = b;
    return strcmp(*pp1, *pp2);
}

void print(string_array names)
{
    for (int i = 0; i < names.size; ++i)
        puts(names.array[i]);
}

void free_strings(string_array names)
{
    for (int i = 0; i < names.size; ++i)
        free(names.array[i]);
    free(names.array);
}
