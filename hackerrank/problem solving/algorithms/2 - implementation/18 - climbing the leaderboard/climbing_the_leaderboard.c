// Source: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

void read_input_and_initialize_arguments(int **ranked, int *n1, int **player, int *n2);
    int* read_line_as_int_array(const int n);
    int* free_pointer_and_return_null(int *pointer);

int remove_duplicates(int *ranked, int n);

void find_result_and_print(const int *ranked, const int n1, const int *player, const int n2);
    int* climbing_leaderboard(int *ranked, int n1, const int *player, const int n2);
        int binary_search_descending_order(const int *array, const int low, const int high, const int key);

void print_result(const int* result, const int n);


int main() {
    int *ranked, n1;
    int *player, n2;

    read_input_and_initialize_arguments(&ranked, &n1, &player, &n2);

    n1 = remove_duplicates(ranked, n1);

    find_result_and_print(ranked, n1, player, n2);

    return 0;
}

    void read_input_and_initialize_arguments(int **ranked, int *n1, int **player, int *n2) {
        int *input_line = read_line_as_int_array(1);
        *n1 = input_line[0];
        input_line = free_pointer_and_return_null(input_line);

        *ranked = read_line_as_int_array(*n1);

        input_line = read_line_as_int_array(1);
        *n2 = input_line[0];
        input_line = free_pointer_and_return_null(input_line);

        *player = read_line_as_int_array(*n2);
    }

        int* read_line_as_int_array(const int n) {
            int *input_line = (int*) calloc(n, sizeof(int));
            for (int i = 0; i < n; i++)
                scanf("%d", &input_line[i]);
            return input_line;
        }

        int* free_pointer_and_return_null(int *pointer) {
            free(pointer);
            return NULL;
        }

    int remove_duplicates(int *ranked, int n) {
        int n_temp = 0;

        for (int i = 0; i < n - 1; i++)
            if (ranked[i] != ranked[i + 1])
                ranked[n_temp++] = ranked[i];

        ranked[n_temp++] = ranked[n - 1];

        return n_temp;
    }

    void find_result_and_print(const int *ranked, const int n1, const int *player, const int n2) {
        int *result = climbing_leaderboard(ranked, n1, player, n2);
        ranked = free_pointer_and_return_null(ranked);
        player = free_pointer_and_return_null(player);

        print_result(result, n2);
        result = free_pointer_and_return_null(result);
    }

        int* climbing_leaderboard(int *ranked, int n1, const int *player, const int n2) {
            int *player_rank = (int*) calloc(n2, sizeof(int));

            for (int i = 0, last_index = n1 - 1; i < n2; i++) {
                int index = binary_search_descending_order(ranked, 0, last_index, player[i]);
                player_rank[i] = ++index;
            }

            return player_rank;
        }

            int binary_search_descending_order(const int *array, const int low, const int high, const int key) {
                if (high >= low) {
                    int middle = low + (high - low) / 2;

                    if (key == array[middle])
                        return middle;
                    else if (key > array[middle])
                        return binary_search_descending_order(array, low, (middle - 1), key);
                    else
                        return binary_search_descending_order(array, (middle + 1), high, key);
                }
                return low;
            }

        void print_result(const int* result, const int n) {
            for (int i = 0; i < n; i++)
                printf("%d\n", result[i]);
        }
