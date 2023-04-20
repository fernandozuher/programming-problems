// Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int read_a_number();
int* read_an_array(const int SIZE);
int* permutation_equation(const int *ARRAY, const int SIZE);
    int* generate_elements_positions_array(const int *ARRAY, const int SIZE);
    int* generate_permutated_array(const int *ARRAY, const int SIZE);
void print_array(const int *ARRAY, const int SIZE);


int main() {
    const int SIZE = read_a_number();
    const int *ARRAY = read_an_array(SIZE);

    const int *PERMUTATED_ARRAY = permutation_equation(ARRAY, SIZE);
    print_array(PERMUTATED_ARRAY, SIZE);

    return 0;
}

    int read_a_number() {
        int number;
        scanf("%d", &number);
        return number;
    }

    int* read_an_array(const int SIZE) {
        int *array = (int*) calloc(SIZE, sizeof(int));
        for (int i = 0; i < SIZE; i++)
            scanf("%d", &array[i]);
        return array;
    }

    int* permutation_equation(const int *ARRAY, const int SIZE) {
        const int *ELEMENTS_POSITIONS_ARRAY = generate_elements_positions_array(ARRAY, SIZE);
        const int *PERMUTATED_ARRAY = generate_permutated_array(ELEMENTS_POSITIONS_ARRAY, SIZE);
        return PERMUTATED_ARRAY;
    }

        int* generate_elements_positions_array(const int *ARRAY, const int SIZE) {
            int *elements_positions_array = (int*) calloc(SIZE, sizeof(int));
            for (int i = 0; i < SIZE; i++)
                elements_positions_array[ARRAY[i] - 1] = i;
            return elements_positions_array;
        }

        int* generate_permutated_array(const int *ARRAY, const int SIZE) {
            int *permutated_array = (int*) calloc(SIZE, sizeof(int));
            for (int i = 0; i < SIZE; i++)
                permutated_array[i] = ARRAY[ARRAY[i]] + 1;
            return permutated_array;
        }

    void print_array(const int *ARRAY, const int SIZE) {
        for (int i = 0; i < SIZE; i++)
            printf("%d\n", ARRAY[i]);
    }