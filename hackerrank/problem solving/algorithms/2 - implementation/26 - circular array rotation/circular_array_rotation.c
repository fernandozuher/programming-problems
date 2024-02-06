// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* read_int_array(const int n);
int reduce_rotations(const int n, const const int rotation_count);
int* rotate_array(int* const array, const int n, const int rotation_count);
void print_array_according_to_index_from_another_array(const int* const array1, const int* const array2, const int n2);

int main()
{
    int n, rotation_count, n_queries;
    scanf("%d %d %d", &n, &rotation_count, &n_queries);
    int *array = read_int_array(n);
    int *queries = read_int_array(n_queries);

    rotation_count = reduce_rotations(n, rotation_count);
    int *rotated_array = rotate_array(array, n, rotation_count);
    print_array_according_to_index_from_another_array(rotated_array, queries, n_queries);

    free(array);
    free(rotated_array);
    free(queries);
    array = rotated_array = queries = NULL;

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    int reduce_rotations(const int n, const int rotation_count)
    {
        if (n > 1)
            return rotation_count >= n ? rotation_count % n : rotation_count;
        return 0;
    }

    int* rotate_array(int* const array, const int n, const int rotation_count)
    {
        int *new_array = (int*) calloc(n, sizeof(int));

        int *first_part_new_array_address = new_array;
        int *second_part_new_array_address = new_array + rotation_count;

        int *first_part_array_begin_address = array;
        int first_part_n = (n - rotation_count) * sizeof(*array);

        int *second_part_array_begin_address = &array[n - rotation_count];
        int second_part_n = rotation_count * sizeof(*array);

        memcpy(first_part_new_array_address, second_part_array_begin_address, second_part_n);
        memcpy(second_part_new_array_address, first_part_array_begin_address, first_part_n);

        return new_array;
    }

    void print_array_according_to_index_from_another_array(const int* const array1, const int* const array2, const int n2)
    {
        for (int i = 0; i < n2; printf("%d\n", array1[array2[i++]]));
    }
