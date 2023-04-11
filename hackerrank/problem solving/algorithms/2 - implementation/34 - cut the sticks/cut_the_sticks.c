// Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int read_a_number();
int* read_an_array(const int SIZE);

int** cut_the_sticks(int* array, const int SIZE);
    void sort_array(int* array, const int SIZE);
        int compare_function(const void* A, const void* B);

    int** initialize_result(const int SIZE);
    void calculate_remaining_sticks_in_each_iteration(int* array, const int SIZE, int** remaining_sticks_in_each_iteration);
        int find_first_element_index_different_of_first_current_shortest_stick_length_index(int index, const int SIZE, const int* ARRAY);
        void decrease_sticks_lengths_higher_than_current_shortest_stick_length(int index, const int SIZE, int* array, const int SHORTEST_STICK_LENGTH);

void print_array(const int* ARRAY, const int SIZE);
int* free_array(int* array);
int** free_multidimensional_array(int** array, const int SIZE);


int main() {
    const int SIZE = read_a_number();
    int* array = read_an_array(SIZE);

    int** result = cut_the_sticks(array, SIZE);
    print_array(result[0], *result[1]);

    array = free_array(array);
    result = free_multidimensional_array(result, 2);

    return 0;
}

    int read_a_number() {
        int number;
        scanf("%d", &number);
        return number;
    }

    int* read_an_array(const int SIZE) {
        int* array = (int*) calloc(SIZE, sizeof(int));
        for (int i = 0; i < SIZE; i++)
            scanf("%d", &array[i]);
        return array;
    }

    int** cut_the_sticks(int* array, const int SIZE) {
        sort_array(array, SIZE);
        int** remaining_sticks_in_each_iteration = initialize_result(SIZE);
        calculate_remaining_sticks_in_each_iteration(array, SIZE, remaining_sticks_in_each_iteration);
        return remaining_sticks_in_each_iteration;
    }

        void sort_array(int* array, const int SIZE) {
            qsort(array, SIZE, sizeof(int), compare_function);
        }

            int compare_function(const void* A, const void* B) {
                return (*(int*)A - * (int*)B);
            }

        int** initialize_result(const int SIZE) {
            int** remaining_sticks_in_each_iteration = (int**) calloc(2, sizeof(int*));
            remaining_sticks_in_each_iteration[0] = (int*) calloc(SIZE, sizeof(int));
            remaining_sticks_in_each_iteration[1] = (int*) calloc(1, sizeof(int));
            remaining_sticks_in_each_iteration[0][0] = SIZE;
            remaining_sticks_in_each_iteration[1][0] = 1;
            return remaining_sticks_in_each_iteration;
        }

        void calculate_remaining_sticks_in_each_iteration(int* array, const int SIZE, int** remaining_sticks_in_each_iteration) {
            int result_size = remaining_sticks_in_each_iteration[1][0];

            for (int i = 0; i < SIZE; result_size++) {
                const int SHORTEST_STICK_LENGTH = array[i];

                i = find_first_element_index_different_of_first_current_shortest_stick_length_index(i, SIZE, array);
                int CURRENT_ITERATION_SIZE = SIZE - i;
                if (i == SIZE)
                    break;

                remaining_sticks_in_each_iteration[0][result_size] = CURRENT_ITERATION_SIZE;
                decrease_sticks_lengths_higher_than_current_shortest_stick_length(i, SIZE, array, SHORTEST_STICK_LENGTH);
            }

            remaining_sticks_in_each_iteration[1][0] = result_size;
        }

            int find_first_element_index_different_of_first_current_shortest_stick_length_index(int index, const int SIZE, const int* ARRAY) {
                const int SHORTEST_STICK_LENGTH = ARRAY[index];
                for (; index < SIZE && ARRAY[index] == SHORTEST_STICK_LENGTH; index++);
                return index;
            }

            void decrease_sticks_lengths_higher_than_current_shortest_stick_length(int index, const int SIZE, int* array, const int SHORTEST_STICK_LENGTH) {
                for (int k = index; k < SIZE; k++)
                    array[k] -= SHORTEST_STICK_LENGTH;
            }

    void print_array(const int* ARRAY, const int SIZE) {
        for (int i = 0; i < SIZE; i++)
            printf("%d\n", ARRAY[i]);
    }

    int* free_array(int* array) {
        free(array);
        return NULL;
    }

    int** free_multidimensional_array(int** array, const int SIZE) {
        for (int i = 0; i < SIZE; i++)
            free(array[i]);
        free(array);
        return NULL;
    }
