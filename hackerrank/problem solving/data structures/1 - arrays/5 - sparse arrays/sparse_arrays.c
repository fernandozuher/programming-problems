// https://www.hackerrank.com/challenges/sparse-arrays/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_STRING 21

char** read_lines(const int n);
int cmp(const void* const s1, const void* const s2);
int* read_queries_and_count_matches(char** input, const int n, const int n_queries);
void print_array(const int* const array, const int n);
char** free_matrix(char** matrix, const int n);

int main()
{
    int n;
    scanf("%d", &n);
    char **input_strings = read_lines(n);
    qsort(input_strings, n, sizeof(char*), cmp);

    int n_queries;
    scanf("%d", &n_queries);
    int *result = read_queries_and_count_matches(input_strings, n, n_queries);
    print_array(result, n_queries);

    input_strings = free_matrix(input_strings, n);
    free(result);
    result = NULL;

    return 0;
}

    char** read_lines(const int n)
    {
        char **array = (char**) calloc(n, sizeof(char*));
        for (int i = 0; i < n; ++i) {
            array[i] = (char*) calloc(MAX_SIZE_STRING, sizeof(char));
            scanf("%s", array[i]);
        }
        return array;
    }

    int cmp(const void *a, const void *b)
    {
        return strcmp(*(const char**)a, *(const char**)b);
    }

    int* read_queries_and_count_matches(char** input, const int n, const int n_queries)
    {
        int *result = (int*) calloc(n_queries, sizeof(int));
        char query[MAX_SIZE_STRING];

        for (int i = 0, count = 0; i < n_queries; ++i, count = 0) {
            scanf("%s", query);

            int j = 0;
            // Since input is sorted, look until find the first key or not
            for (; j < n && strcmp(query, input[j]) != 0; ++j);

            // If key was found
            if (j < n)
                for (; j < n && strcmp(query, input[j]) == 0; ++j)
                    ++count;
            result[i] = count;
        }

        return result;
    }

    void print_array(const int* const array, const int n)
    {
        for (int i = 0; i < n; ++i)
            printf("%d\n", array[i]);
    }

    char** free_matrix(char** matrix, const int n)
    {
        for (int i = 0; i < n; ++i)
            free(matrix[i]);
        free(matrix);
        return NULL;
    }
