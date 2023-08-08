// https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 21
#define MAX_PHONE_LENGTH 11

typedef struct {
    char name[21];
    char phone[11];
} contact;

contact* read_contacts(const int n);
int compare_contacts(const void *a, const void *b);
void check_name(const contact *contacts, const int n);
    int compare_contacts_to_binary_search(const void *key, const void *array);

int main()
{
    int n;
    scanf("%d", &n);

    contact *contacts = read_contacts(n);
    qsort(contacts, n, sizeof(contact), compare_contacts);
    check_name(contacts, n);

    return 0;
}

    contact* read_contacts(const int n)
    {
        contact *contacts = (contact*) calloc(n, sizeof(contact));
        char name[MAX_NAME_LENGTH], phone[MAX_PHONE_LENGTH];

        for (int i = 0; i < n; ++i) {
            scanf("%20s %10s", name, phone);
            strcpy(contacts[i].name, name);
            strcpy(contacts[i].phone, phone);
        }

        return contacts;
    }

    int compare_contacts(const void *a, const void *b)
    {
        contact const *const l = a;
        contact const *const r = b;
        return strcmp(l->name, r->name);
    }

    void check_name(const contact *contacts, const int n)
    {
        for (char query[MAX_NAME_LENGTH]; scanf("%s", query) != EOF;) {
            const contact *result = bsearch(query, contacts, n, sizeof(contact), compare_contacts_to_binary_search);

            if (result)
                printf("%s=%s\n", result->name, result->phone);
            else
                puts("Not found");
        }
    }

        int compare_contacts_to_binary_search(const void *key, const void *array)
        {
            char const *const l = key;
            contact const *const r = array;
            return strcmp(l, r->name);
        }
