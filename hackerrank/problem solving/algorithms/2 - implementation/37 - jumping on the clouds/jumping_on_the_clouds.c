// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int read_a_number();
int* read_an_array(const int SIZE);
int calculate_minimum_number_of_jumps(const int* ARRAY, const int ARRAY_SIZE);
    int get_index_of_next_jump(int index, const int* ARRAY, const int SIZE);
        bool is_next_second_index_inside_range(const int INDEX, const int SIZE);
        bool is_next_second_cloud_cumulus(const int TYPE_OF_CLOUD);
int* free_array(int* array);


int main() {
    const int N_CLOUDS = read_a_number();
    int* cloud_array = read_an_array(N_CLOUDS);
    const int MINIMUM_NUMBER_OF_JUMPS = calculate_minimum_number_of_jumps(cloud_array, N_CLOUDS);
    printf("%d\n", MINIMUM_NUMBER_OF_JUMPS);

    cloud_array = free_array(cloud_array);

    return 0;
}

    int read_a_number() {
        int number;
        scanf("%d", &number);
        return number;
    }

    int* read_an_array(const int SIZE) {
        int* array = (int*) calloc(SIZE, sizeof(int));
        for (int i = 0; i < SIZE; ++i)
            scanf("%d", &array[i]);
        return array;
    }

    int calculate_minimum_number_of_jumps(const int* ARRAY, const int ARRAY_SIZE) {
        int jumps = 0;

        for (int i = 0, size = ARRAY_SIZE - 1; i < size; ) {
            i = get_index_of_next_jump(i, ARRAY, ARRAY_SIZE);
            jumps++;
        }

        return jumps;
    }

        int get_index_of_next_jump(int index, const int* ARRAY, const int SIZE) {
            if (is_next_second_index_inside_range(index + 2, SIZE))
                index += is_next_second_cloud_cumulus(ARRAY[index + 2]) ? 2 : 1;
            else
                index++;
            return index;
        }

            bool is_next_second_index_inside_range(const int INDEX, const int SIZE) {
                return INDEX < SIZE;
            }

            bool is_next_second_cloud_cumulus(const int TYPE_OF_CLOUD) {
                return TYPE_OF_CLOUD == 0;
            }

    int* free_array(int* array) {
        free(array);
        return NULL;
    }
