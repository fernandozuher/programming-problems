// Source: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_line_as_int_array(const int n);
int* free_pointer_and_return_null(int *pointer);
int* climbing_leaderboard(int *ranked, int n1, const int *player, const int n2);
    int remove_duplicates(int *ranked, int n);
    int binary_search_descending_order(const int *array, const int low, const int high, const int key);
void print_result(const int* result, const int n);


int main() {
    int *input_line = read_line_as_int_array(1);
    const int n1 = input_line[0];
    input_line = free_pointer_and_return_null(input_line);

    int *ranked = read_line_as_int_array(n1);

    input_line = read_line_as_int_array(1);
    const int n2 = input_line[0];
    input_line = free_pointer_and_return_null(input_line);

    int *player = read_line_as_int_array(n2);

    int *result = climbing_leaderboard(ranked, n1, player, n2);
    ranked = free_pointer_and_return_null(ranked);
    player = free_pointer_and_return_null(player);

    print_result(result, n2);
    result = free_pointer_and_return_null(result);

    return 0;
}

int* read_line_as_int_array(const int n) {
    int *input_line = (int*) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%u", &input_line[i]);
    return input_line;
}

int* free_pointer_and_return_null(int *pointer) {
    free(pointer);
    return NULL;
}

int* climbing_leaderboard(int *ranked, int n1, const int *player, const int n2) {
    int *player_rank = (int*) calloc(n2, sizeof(int));
    n1 = remove_duplicates(ranked, n1);

    for (int i = 0; i < n2; i++) {
        int index = binary_search_descending_order(ranked, 0, n1, player[i]);
        index = index <= n1 - 1 ? index + 1 : index;
        player_rank[i] = index;
    }

    return player_rank;
}

    int remove_duplicates(int *ranked, int n) {
        int temp_ranked[n];
        int n_temp = 0;
        int i;

        for (i = 0; i < n - 1; i++)
            if (ranked[i] != ranked[i + 1])
                temp_ranked[n_temp++] = ranked[i];

        temp_ranked[n_temp++] = ranked[n - 1];

        for (i = 0; i < n_temp; i++)
            ranked[i] = temp_ranked[i];

        return n_temp;
    }

    int binary_search_descending_order(const int *array, const int low, const int high, const int key) {
        if (high >= low) {
            int middle = (low + high) / 2;

            if (key == array[middle])
                return middle;
            else if (key > array[middle])
                return binary_search_descending_order(array, low, (middle - 1), key);
            else if (key < array[middle])
                return binary_search_descending_order(array, (middle + 1), high, key);
        }
        return low;
    }

void print_result(const int* result, const int n) {
    for (int i = 0; i < n; i++)
        printf("%d\n", result[i]);
}
