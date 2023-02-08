// Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

#include <string.h>
#include <stdbool.h>

int* is_there_rotation(const int* ARRAY, const int ARRAY_SIZE, const int ROTATION);
    int reduce_rotations(const int ARRAY_SIZE, const int ROTATION);
    int* rotate_elements(const int A[], const int ARRAY_SIZE, const int ROTATION);


struct Results solution(int A[], const int N, const int K) {
    const int *ROTATED_ARRAY = is_there_rotation(A, N, K);

    if (ROTATED_ARRAY != NULL)
        return (struct Results) {ROTATED_ARRAY, N};
    else
        return (struct Results) {A, N};
}

    int* is_there_rotation(const int* ARRAY, const int ARRAY_SIZE, const int ROTATION) {
        const int NEW_ROTATION = reduce_rotations(ARRAY_SIZE, ROTATION);

        if (NEW_ROTATION > 0) {
            int *rotated_array = rotate_elements(ARRAY, ARRAY_SIZE, NEW_ROTATION);
            return rotated_array;
        }
        else
            return NULL;
    }

        int reduce_rotations(const int ARRAY_SIZE, const int ROTATION) {
            if (ARRAY_SIZE > 1)
                return ROTATION >= ARRAY_SIZE ? ROTATION % ARRAY_SIZE : ROTATION;
            else
                return 0;
        }

        int* rotate_elements(const int ARRAY[], const int ARRAY_SIZE, const int ROTATION) {
            int *new_array = (int*) calloc(ARRAY_SIZE, sizeof(int));

            memcpy(new_array, &ARRAY[ARRAY_SIZE - ROTATION], ROTATION * sizeof(*ARRAY));
            memcpy(new_array + ROTATION, ARRAY, (ARRAY_SIZE - ROTATION) * sizeof(*ARRAY));

            return new_array;
        }
