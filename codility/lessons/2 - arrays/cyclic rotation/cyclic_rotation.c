// Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

#include <string.h>
#include <stdbool.h>

int reduce_numbers_of_rotations(const int ROTATION, const int ARRAY_SIZE);
int* rotate_array_elements(const int A[], const int ARRAY_SIZE, const int ROTATION);


struct Results solution(int A[], const int N, const int K) {
    int new_rotation;

    if (N > 1 && (new_rotation = reduce_numbers_of_rotations(K, N)) > 0) {
        int *rotated_array = rotate_array_elements(A, N, new_rotation);
        return (struct Results) {rotated_array, N};
    }
    else
        return (struct Results) {A, N};
}

    int reduce_numbers_of_rotations(const int ROTATION, const int ARRAY_SIZE) {
        const int NEW_ROTATION = ROTATION >= ARRAY_SIZE ? ROTATION % ARRAY_SIZE : ROTATION;
        return NEW_ROTATION;
    }

    int* rotate_array_elements(const int A[], const int ARRAY_SIZE, const int ROTATION) {
        int *array = (int*) calloc(ARRAY_SIZE, sizeof(int));
        memcpy(array, &A[ARRAY_SIZE - ROTATION], ROTATION * sizeof(*A));
        memcpy(array + ROTATION, A, (ARRAY_SIZE - ROTATION) * sizeof(*A));
        return array;
    }
