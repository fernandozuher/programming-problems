// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int n;
} array;

array* initialize_array(const int n);
array* dynamic_array(array *a, const int n, const int* const query, array *answers, int *last_answer);
    array* realloc_array(array *a, const int index);
void print_array(const int* const a, const int n);
void free_inner_arrays(array *a, const int n);

int main()
{
    int n, n_queries;
    scanf("%d %d", &n, &n_queries);

    array *a = initialize_array(n);
    array *answers = initialize_array(1);

    for (int i = 0, query_size = 3, last_answer = 0; i < n_queries; ++i) {
        int query[query_size];
        scanf("%d %d %d", &query[0], &query[1], &query[2]);
        answers = dynamic_array(a, n, query, answers, &last_answer);
    }

    print_array(answers->arr, answers->n);

    free_inner_arrays(a, n);
    free_inner_arrays(answers, 1);
    a = answers = NULL;

    return 0;
}

    array* initialize_array(const int n)
    {
        array *a = (array*) calloc(n, sizeof(array));
        for (int i = 0; i < n; ++i) {
            a[i].arr = NULL;
            a[i].n = 0;
        }
        return a;
    }

    array* dynamic_array(array *a, const int n, const int* const query, array *answers, int *last_answer)
    {
        int type = query[0], x = query[1], y = query[2];
        int index = (x ^ (*last_answer)) % n;

        if (type == 1) {
            a = realloc_array(a, index);
            int j = a[index].n - 1;
            a[index].arr[j] = y;
        }
        else {
            answers = realloc_array(answers, 0);
            int i = answers->n - 1;

            int j = y % a[index].n;
            *last_answer = a[index].arr[j];

            answers->arr[i] = *last_answer;
        }

        return answers;
    }

        array* realloc_array(array *a, const int index)
        {
            ++a[index].n;
            a[index].arr = (int*) realloc(a[index].arr, a[index].n * sizeof(int));
            return a;
        }

    void print_array(const int* const a, const int n)
    {
        for (int i = 0; i < n; ++i)
            printf("%d\n", a[i]);
    }

    void free_inner_arrays(array *a, const int n)
    {
        for (int i = 0; i < n; ++i)
            free(a[i].arr);
        free(a);
    }
