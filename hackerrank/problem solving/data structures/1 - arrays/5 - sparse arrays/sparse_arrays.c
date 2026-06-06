// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_STRING 21 // 20 + '\0'

char **read_lines(int n, int string_size);
int *counts_from(char **strings, int n, char **queries, int n_queries);
int count_if(char **arr, int n, const char *query);
void free_char_array(char **arr, int n);

int main()
{
    int n;
    scanf("%d", &n);
    char **strings = read_lines(n, MAX_SIZE_STRING);

    int n_queries;
    scanf("%d", &n_queries);
    char **queries = read_lines(n_queries, MAX_SIZE_STRING);

    int *res = counts_from(strings, n, queries, n_queries);

    for (int i = 0; i < n_queries; ++i)
        printf("%d\n", res[i]);

    free_char_array(strings, n);
    free_char_array(queries, n_queries);
    free(res);

    return 0;
}

char **read_lines(int n, int string_size)
{
    auto arr = (char **) malloc(n * sizeof(char *));
    for (int i = 0; i < n; ++i) {
        arr[i] = (char *) malloc(string_size * sizeof(char));
        scanf("%s", arr[i]);
    }
    return arr;
}

// MAX_SIZE_STRING: 21
// T: O(n_queries * n * MAX_SIZE_STRING) = O(n_queries * n * 21) = O(n_queries * n)
// S: O(n_queries) extra space
int *counts_from(char **strings, int n, char **queries, int n_queries)
{
    auto arr = (int *) malloc(n_queries * sizeof(int));
    for (int i = 0; i < n_queries; ++i)
        arr[i] = count_if(strings, n, queries[i]);
    return arr;
}

int count_if(char **arr, int n, const char *query)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (!strcmp(arr[i], query))
            ++count;
    return count;
}

void free_char_array(char **arr, int n)
{
    for (int i = 0; i < n; ++i)
        free(arr[i]);
    free(arr);
}
