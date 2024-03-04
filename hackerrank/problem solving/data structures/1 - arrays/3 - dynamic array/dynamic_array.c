// https://www.hackerrank.com/challenges/dynamic-array/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int n;
} array;

array* read_queries(const int n);
array* dynamic_array(const array* const queries, const int n_queries, const int n);
    int get_answers_size(const array* const queries, const int n_queries);
    array* initialize_answers(const int array_size, const int n);
    array* initialize_array(const int n);
    array* realloc_array(array *a, const int index);

int main()
{
    int n, n_queries;
    scanf("%d %d", &n, &n_queries);

    array *queries = read_queries(n_queries);
    array *result = dynamic_array(queries, n_queries, n);

    for (int i = 0, size = result->n; i < size; ++i)
        printf("%d\n", result->arr[i]);

    free(queries);
    free(result);
    queries = result = NULL;

    return 0;
}

    array* read_queries(const int n)
    {
        array *queries = (array*) calloc(n, sizeof(array));

        for (int i = 0, query_size = 3; i < n; ++i) {
            queries[i].arr = (int*) calloc(query_size, sizeof(int));
            queries[i].n = query_size;
            for (int j = 0; j < query_size; ++j)
                scanf("%d", &queries[i].arr[j]);
        }

        return queries;
    }

    array* dynamic_array(const array* const queries, const int n_queries, const int n)
    {
        int answers_size = get_answers_size(queries, n_queries);
        array *answers = initialize_answers(sizeof(array), answers_size);
        int n_answers = 0;
        int last_answer = 0;
        array *temp_array = initialize_array(n);

        for (int i = 0; i < n_queries; ++i) {
            int type = queries[i].arr[0];
            int x = queries[i].arr[1];
            int y = queries[i].arr[2];

            int index = (x ^ last_answer) % n;

            if (type == 1) {
                temp_array = realloc_array(temp_array, index);
                int j = temp_array[index].n - 1;
                temp_array[index].arr[j] = y;
            }
            else {
                int j = y % temp_array[index].n;
                last_answer = temp_array[index].arr[j];
                answers->arr[n_answers++] = last_answer;
            }
        }

        free(temp_array);
        temp_array = NULL;

        return answers;
    }

        int get_answers_size(const array* const queries, const int n_queries)
        {
            int answers_size = 0;
            for (int i = 0; i < n_queries; ++i)
                if (queries[i].arr[0] == 2)
                    ++answers_size;
            return answers_size;
        }

        array* initialize_answers(const int array_size, const int n)
        {
            array *answers = (array*) calloc(1, sizeof(array_size));
            answers->arr = (int*) calloc(n, sizeof(int));
            answers->n = n;
            return answers;
        }

        array* initialize_array(const int n)
        {
            array *temp_array = (array*) calloc(n, sizeof(array));
            for (int i = 0; i < n; ++i) {
                temp_array[i].arr = NULL;
                temp_array[i].n = 0;
            }
            return temp_array;
        }

        array* realloc_array(array *a, const int index)
        {
            ++a[index].n;
            a[index].arr = (int*) realloc(a[index].arr, a[index].n * sizeof(int));
            return a;
        }
