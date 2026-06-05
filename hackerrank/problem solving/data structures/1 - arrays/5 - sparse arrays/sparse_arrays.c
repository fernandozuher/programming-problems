// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true
// C23

#include <stdio.h>
#include <string.h>

#define MAX_SIZE_STRING 21

void read_lines(char arr[][MAX_SIZE_STRING], int n);
void counts_from(char strings[][MAX_SIZE_STRING], int n, char queries[][MAX_SIZE_STRING], int n_queries, int res[]);
int count_if(char arr[][MAX_SIZE_STRING], int n, char query[]);

int main()
{
    int n;
    scanf("%d", &n);
    char strings[n][MAX_SIZE_STRING];
    read_lines(strings, n);

    int n_queries;
    scanf("%d", &n_queries);
    char queries[n_queries][MAX_SIZE_STRING];
    read_lines(queries, n_queries);

    int res[n_queries];
    counts_from(strings, n, queries, n_queries, res);

    for (int i = 0; i < n_queries; ++i)
        printf("%d\n", res[i]);

    return 0;
}

void read_lines(char arr[][MAX_SIZE_STRING], int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%s", arr[i]);
}

// MAX_SIZE_STRING: 21
// T: O(n_queries * n * MAX_SIZE_STRING) = O(n_queries * n * 21) = O(n_queries * n)
// S: O(1) extra space
void counts_from(char strings[][MAX_SIZE_STRING], int n, char queries[][MAX_SIZE_STRING], int n_queries, int res[])
{
    for (int i = 0; i < n_queries; ++i)
        res[i] = count_if(strings, n, queries[i]);
}

int count_if(char arr[][MAX_SIZE_STRING], int n, char query[])
{
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (!strcmp(arr[i], query))
            ++count;
    return count;
}
