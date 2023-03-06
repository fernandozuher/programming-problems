// Source: https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** read_input();
    int* read_a_number_and_return_it_into_array();
    int* read_array(const int SIZE);

int** reduce_input_rotations(int **input);
int** rotate_input_array(int **input);
void print_rotated_array_elements_according_to_queries(int **input);

void* free_allocated_data(int **input);


int main() {
    int **input = read_input();

    input = reduce_input_rotations(input);
    input = rotate_input_array(input);
    print_rotated_array_elements_according_to_queries(input);

    input = free_allocated_data(input);

    return 0;
}

    int** read_input() {
        int *array_size = read_a_number_and_return_it_into_array();
        int *rotation_count = read_a_number_and_return_it_into_array();
        int *queries_size = read_a_number_and_return_it_into_array();

        int *array = read_array(*array_size);
        int *queries = read_array(*queries_size);

        int **input = (int**) calloc(5, sizeof(int*));
        input[0] = array;
        input[1] = array_size;
        input[2] = rotation_count;
        input[3] = queries;
        input[4] = queries_size;

        return input;
    }

        int* read_a_number_and_return_it_into_array() {
            int *number = (int*) calloc(1, sizeof(int));
            scanf("%d", number);
            return number;
        }

        int* read_array(const int SIZE) {
            int *array = (int*) calloc(SIZE, sizeof(int));
            for (int i = 0; i < SIZE; i++)
                scanf("%d", &array[i]);
            return array;
        }

    int** reduce_input_rotations(int **input) {
        const int ARRAY_SIZE = *input[1];
        int ROTATION_COUNT = *input[2];

        if (ARRAY_SIZE > 1)
            *input[2] = ROTATION_COUNT = ROTATION_COUNT >= ARRAY_SIZE ? ROTATION_COUNT % ARRAY_SIZE : ROTATION_COUNT;
        else
            *input[2] = ROTATION_COUNT = 0;

        return input;
    }

    int** rotate_input_array(int **input) {
        const int *ARRAY = input[0];
        const int ARRAY_SIZE = *input[1];
        const int ROTATION_COUNT = *input[2];
        int *new_array = (int*) calloc(ARRAY_SIZE, sizeof(int));

        const int *FIRST_PART_NEW_ARRAY_ADDRESS = new_array;
        const int *SECOND_PART_NEW_ARRAY_ADDRESS = new_array + ROTATION_COUNT;

        const int *FIRST_PART_ARRAY_BEGIN_ADDRESS = ARRAY;
        const int FIRST_PART_ARRAY_SIZE = (ARRAY_SIZE - ROTATION_COUNT) * sizeof(*ARRAY);

        const int *SECOND_PART_ARRAY_BEGIN_ADDRESS = &ARRAY[ARRAY_SIZE - ROTATION_COUNT];
        const int SECOND_PART_ARRAY_SIZE = ROTATION_COUNT * sizeof(*ARRAY);

        memcpy(FIRST_PART_NEW_ARRAY_ADDRESS, SECOND_PART_ARRAY_BEGIN_ADDRESS, SECOND_PART_ARRAY_SIZE);
        memcpy(SECOND_PART_NEW_ARRAY_ADDRESS, FIRST_PART_ARRAY_BEGIN_ADDRESS, FIRST_PART_ARRAY_SIZE);

        input[0] = new_array;
        return input;
    }

    void print_rotated_array_elements_according_to_queries(int **input) {
        const int *ARRAY = input[0];
        const int *QUERIES = input[3];
        const int QUERIES_SIZE = *input[4];

        for (int i = 0; i < QUERIES_SIZE; i++)
            printf("%d\n", ARRAY[QUERIES[i]]);
    }

    void* free_allocated_data(int **input) {
        for (int i = 0, size = 5; i < size; i++)
            free(input[i]);
        free(input);

        return NULL;
    }
