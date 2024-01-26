// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_int_array(const int n);
int* remove_duplicates(int *array, int *n);
int* climbing_leaderboard(const int* const ranked, const int n1, const int* const player, const int n2);
    int binary_search_descending_order(const int* const array, const int low, const int high, const int key);
void print_array(const int* const array, const int n);

int main()
{
    int n1;
    scanf("%d", &n1);
    int *ranked = read_int_array(n1);
    ranked = remove_duplicates(ranked, &n1);

    int n2;
    scanf("%d", &n2);
    int *player = read_int_array(n2);

    int *output = climbing_leaderboard(ranked, n1, player, n2);
    print_array(output, n2);

    free(ranked);
    free(player);
    free(output);
    ranked = player = output = NULL;

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    int* remove_duplicates(int *array, int *n)
    {
        int new_size = 0;

        for (int i = 0, size = *n - 1; i < size; ++i)
            if (array[i] != array[i + 1])
                array[new_size++] = array[i];

        array[new_size++] = array[*n - 1];
        *n = new_size;

        return realloc(array, new_size * sizeof(int));
    }

    int* climbing_leaderboard(const int* const ranked, const int n1, const int* const player, const int n2)
    {
        int *player_rank = (int*) calloc(n2, sizeof(int));

        for (int i = 0, last_index = n1 - 1; i < n2; ++i) {
            int index = binary_search_descending_order(ranked, 0, last_index, player[i]);
            player_rank[i] = ++index;
        }

        return player_rank;
    }

        int binary_search_descending_order(const int* const array, const int low, const int high, const int key)
        {
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

    void print_array(const int* const array, const int n)
    {
        for (int i = 0; i < n; ++i)
            printf("%d\n", array[i]);
    }
