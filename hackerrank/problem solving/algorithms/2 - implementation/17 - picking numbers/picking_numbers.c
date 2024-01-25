// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_int_array(const int n);
int compare (const void* const a, const void* const b);
int picking_numbers(const int* const numbers, const int n);
int* update_first_reference_number_index_and_subarray_current_size(const int* const numbers, const int i, const int second_reference_number_index);
int update_subarray_biggest_size(const int subarray_biggest_size, const int subarray_current_size);

int main()
{
    int n;
    scanf("%d", &n);

    int *array = read_int_array(n);
    qsort(array, n, sizeof(int), compare);

    printf("%d\n", picking_numbers(array, n));

    free(array);
    array = NULL;

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[++i]));
        return array;
    }

        int compare (const void* const a, const void* const b)
        {
            return *(int*) a - *(int*) b;
        }

    int picking_numbers(const int* const numbers, const int n)
    {
        int subarray_biggest_size = 0;
        int first_reference_number_index = 0;
        int second_reference_number_index = 0;
        int subarray_current_size = 1;

        for (int i = 1; i < n; ++i) {
            int difference = numbers[i] - numbers[first_reference_number_index];

            switch (difference) {
            case 0:
                ++subarray_current_size;
                break;

            case 1:
                ++subarray_current_size;
                if (numbers[second_reference_number_index] != numbers[i])
                    second_reference_number_index = i;
                break;

            default:
                subarray_biggest_size = update_subarray_biggest_size(subarray_biggest_size, subarray_current_size);

                int *update = update_first_reference_number_index_and_subarray_current_size(numbers, i, second_reference_number_index);

                first_reference_number_index = update[0];
                second_reference_number_index = i;
                subarray_current_size = update[1];

                free(update);
            }
        }

        return update_subarray_biggest_size(subarray_biggest_size, subarray_current_size);
    }

        int update_subarray_biggest_size(const int subarray_biggest_size, const int subarray_current_size)
        {
            return subarray_current_size > subarray_biggest_size ? subarray_current_size : subarray_biggest_size;
        }

        int* update_first_reference_number_index_and_subarray_current_size(const int* const numbers, const int i, const int second_reference_number_index)
        {
            int first_reference_number_index, subarray_current_size;

            if (numbers[i] - numbers[second_reference_number_index] == 1) {
                first_reference_number_index = second_reference_number_index;
                subarray_current_size = i - second_reference_number_index + 1;
            }
            else {
                first_reference_number_index = i;
                subarray_current_size = 1;
            }

            int *obj = (int*) calloc(2, sizeof(int));
            obj[0] = first_reference_number_index;
            obj[1] = subarray_current_size;

            return obj;
        }
