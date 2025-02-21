// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true
// From C23 onwards: auto, nullptr

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 21
#define MAX_PHONE_LENGTH 11

typedef struct {
    char name[21];
    char phone[11];
} contact;

contact *init_phone_book(int n);
int compare_names(const void *a, const void *b);
void query_names(const contact *phone_book, int n);
int compare_contacts(const void *key, const void *array);

int main()
{
    int n;
    scanf("%d", &n);
    contact *phone_book = init_phone_book(n);
    qsort(phone_book, n, sizeof(contact), compare_names);
    query_names(phone_book, n);

    free(phone_book);
    phone_book = nullptr;

    return 0;
}

contact *init_phone_book(const int n)
{
    auto phone_book = (contact *) malloc(n * sizeof(contact));
    for (int i = 0; i < n; ++i)
        scanf("%20s %10s", phone_book[i].name, phone_book[i].phone);
    return phone_book;
}

int compare_names(const void *a, const void *b)
{
    const contact *const l = a;
    const contact *const r = b;
    return strcmp(l->name, r->name);
}

void query_names(const contact *phone_book, const int n)
{
    for (char query[MAX_NAME_LENGTH]; scanf("%s", query) != EOF;) {
        contact *result = bsearch(query, phone_book, n, sizeof(contact), compare_contacts);

        if (result)
            printf("%s=%s\n", result->name, result->phone);
        else
            puts("Not found");
    }
}

int compare_contacts(const void *key, const void *array)
{
    char const *const l = key;
    contact const *const r = array;
    return strcmp(l, r->name);
}
