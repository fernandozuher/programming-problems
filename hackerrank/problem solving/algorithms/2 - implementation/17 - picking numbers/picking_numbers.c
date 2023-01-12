// Source: https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_line_as_int_array(const int n);
int compare (const void *a, const void *b);
int picking_numbers(const int *numbers, const int n);
    int* update_first_reference_number_index_and_subarray_current_size(const int *numbers, const int i, const int second_reference_number_index);
    int update_subarray_biggest_size(const int subarray_biggest_size, const int subarray_current_size);


int main() {
    int *input_line = read_line_as_int_array(1);
    const int n = input_line[0];
    free(input_line);
    input_line = NULL;

    int *numbers = read_line_as_int_array(n);
    qsort(numbers, n, sizeof(int), compare);

    const int result = picking_numbers(numbers, n);
    free(numbers);
    numbers = NULL;

    printf("%d\n", result);

    return 0;
}

    int* read_line_as_int_array(const int n) {
        int *input_line = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &input_line[i]);
        return input_line;
    }

    int compare (const void *a, const void *b) {
        return *(int*) a - *(int*) b;
    }

    int picking_numbers(const int *numbers, const int n) {
        int subarray_biggest_size = 0;
        int first_reference_number_index = 0;
        int second_reference_number_index = 0;
        int subarray_current_size = 1;

        for (int i = 1; i < n; i++) {
            int difference = numbers[i] - numbers[first_reference_number_index];

            switch (difference) {
            case 0:
                subarray_current_size++;
                break;

            case 1:
                subarray_current_size++;
                if (numbers[second_reference_number_index] != numbers[i])
                    second_reference_number_index = i;
                break;

            default:
                subarray_biggest_size = update_subarray_biggest_size(subarray_biggest_size, subarray_current_size);

                const int *update = update_first_reference_number_index_and_subarray_current_size(numbers, i, second_reference_number_index);

                first_reference_number_index = update[0];
                second_reference_number_index = i;
                subarray_current_size = update[1];

                free(update);
            }
        }

        subarray_biggest_size = update_subarray_biggest_size(subarray_biggest_size, subarray_current_size);
        return subarray_biggest_size;
    }

        int update_subarray_biggest_size(const int subarray_biggest_size, const int subarray_current_size) {
            return subarray_current_size > subarray_biggest_size ? subarray_current_size : subarray_biggest_size;
        }

        int* update_first_reference_number_index_and_subarray_current_size(const int *numbers, const int i, const int second_reference_number_index) {
            int first_reference_number_index, subarray_current_size;

            if (numbers[i] - numbers[second_reference_number_index] == 1) {
                first_reference_number_index = second_reference_number_index;
                subarray_current_size = i - second_reference_number_index + 1;
            }
            else {
                first_reference_number_index = i;
                subarray_current_size = 1;
            }

            int *result = (int*) calloc(2, sizeof(int));
            result[0] = first_reference_number_index;
            result[1] = subarray_current_size;

            return result;
        }
