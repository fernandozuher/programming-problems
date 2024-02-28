// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_int_array(const int n);
int compare_function(const void *a, const void *b);

int** cut_the_sticks(int* const array, const int n);
    int** initialize_result(const int n);
    int find_first_element_index_different_of_first_current_shortest_stick_length_index(const int* const array, const int n, int index);
    void decrease_sticks_lengths_higher_than_current_shortest_stick_length(int* const array, const int n, const int index, const int shortest_stick_length);

void print_array(const int* const array, const int n);
int** free_multidimensional_array(int **array, const int n);

int main()
{
    int n;
    scanf("%d", &n);
    int *array = read_int_array(n);
    qsort(array, n, sizeof(int), compare_function);

    int** result = cut_the_sticks(array, n);
    print_array(result[0], *result[1]);

    free(array);
    array = NULL;
    result = free_multidimensional_array(result, 2);

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    int compare_function(const void *a, const void *b)
    {
        return (*(int*)a - * (int*)b);
    }

    int** cut_the_sticks(int* const array, const int n)
    {
        int **remaining_sticks_of_each_iteration = initialize_result(n);
        int result_size = remaining_sticks_of_each_iteration[1][0];

        for (int i = 0; i < n; ++result_size) {
            int shortest_stick_length = array[i];

            i = find_first_element_index_different_of_first_current_shortest_stick_length_index(array, n, i);
            int current_iteration_n = n - i;
            if (i == n)
                break;

            remaining_sticks_of_each_iteration[0][result_size] = current_iteration_n;
            decrease_sticks_lengths_higher_than_current_shortest_stick_length(array, n, i, shortest_stick_length);
        }

        remaining_sticks_of_each_iteration[1][0] = result_size;
        return remaining_sticks_of_each_iteration;
    }

        int** initialize_result(const int n)
        {
            int **remaining_sticks_of_each_iteration = (int**) calloc(2, sizeof(int*));
            remaining_sticks_of_each_iteration[0] = (int*) calloc(n, sizeof(int));
            remaining_sticks_of_each_iteration[1] = (int*) calloc(1, sizeof(int));
            remaining_sticks_of_each_iteration[0][0] = n;
            remaining_sticks_of_each_iteration[1][0] = 1;
            return remaining_sticks_of_each_iteration;
        }

        int find_first_element_index_different_of_first_current_shortest_stick_length_index(const int* const array, const int n, int index)
        {
            int shortest_stick_length = array[index];
            for (; index < n && array[index] == shortest_stick_length; ++index);
            return index;
        }

        void decrease_sticks_lengths_higher_than_current_shortest_stick_length(int* const array, const int n, const int index, const int shortest_stick_length)
        {
            for (int i = index; i < n; ++i)
                array[i] -= shortest_stick_length;
        }

    void print_array(const int* const array, const int n)
    {
        for (int i = 0; i < n; ++i)
            printf("%d\n", array[i]);
    }

    int** free_multidimensional_array(int **array, const int n)
    {
        for (int i = 0; i < n; i++)
            free(array[i]);
        free(array);
        return NULL;
    }
