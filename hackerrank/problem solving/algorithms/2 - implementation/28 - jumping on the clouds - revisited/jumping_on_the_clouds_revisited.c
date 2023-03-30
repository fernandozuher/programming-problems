// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int read_a_number();
int* read_an_array(const int SIZE_ARRAY);
int jumping_on_clouds(const int *ARRAY, const int SIZE_ARRAY, const int JUMP_LENGTH);
    int spent_energy_according_to_type_of_cloud(const int CLOUD_TYPE);
    int generate_new_cloud_index(const int CLOUD_INDEX, const int SIZE_ARRAY, const int JUMP_LENGTH);
    bool is_cloud_index_back_to_first_cloud(const int CLOUD_INDEX);


int main() {
    const int SIZE_ARRAY = read_a_number();
    const int JUMP_LENGTH = read_a_number();
    int *array = read_an_array(SIZE_ARRAY);

    const int ENERGY = jumping_on_clouds(array, SIZE_ARRAY, JUMP_LENGTH);
    printf("%d\n", ENERGY);

    free(array);
    array = NULL;

    return 0;
}

    int read_a_number() {
        int number;
        scanf("%d", &number);
        return number;
    }

    int* read_an_array(const int SIZE_ARRAY) {
        int *array = (int*) calloc(SIZE_ARRAY, sizeof(int));
        for (int i = 0; i < SIZE_ARRAY; i++)
            scanf("%d", &array[i]);
        return array;
    }

    int jumping_on_clouds(const int *ARRAY, const int SIZE_ARRAY, const int JUMP_LENGTH) {
        int energy = 100;

        for (int cloud_index = 0; true; ) {
            energy -= spent_energy_according_to_type_of_cloud(ARRAY[cloud_index]);
            cloud_index = generate_new_cloud_index(cloud_index, SIZE_ARRAY, JUMP_LENGTH);
            if (is_cloud_index_back_to_first_cloud(cloud_index))
                break;
        }

        return energy;
    }

        int spent_energy_according_to_type_of_cloud(const int CLOUD_TYPE) {
            return CLOUD_TYPE == 0 ? 1 : 3;
        }

        int generate_new_cloud_index(const int CLOUD_INDEX, const int SIZE_ARRAY, const int JUMP_LENGTH) {
            return (CLOUD_INDEX + JUMP_LENGTH) % SIZE_ARRAY;
        }

        bool is_cloud_index_back_to_first_cloud(const int CLOUD_INDEX) {
            return CLOUD_INDEX == 0;
        }
