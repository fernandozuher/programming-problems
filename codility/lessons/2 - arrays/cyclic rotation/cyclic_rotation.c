// Source: https://app.codility.com/programmers/lessons/2-arrays/cyclic_rotation/

#include <string.h>
#include <stdbool.h>

int* is_there_rotation(const int* array, const int array_size, const int rotation);
    int reduce_rotations(const int array_size, const int rotation);
    int* rotate_elements(const int* a, const int array_size, const int rotation);

struct Results solution(int a[], const int n, const int k)
{
    int *rotated_array = is_there_rotation(a, n, k);

    if (rotated_array != NULL)
        return (struct Results) {rotated_array, n};
    else
        return (struct Results) {a, n};
}

    int* is_there_rotation(const int* array, const int array_size, const int rotation)
    {
        const int new_rotation = reduce_rotations(array_size, rotation);

        if (new_rotation > 0) {
            int *rotated_array = rotate_elements(array, array_size, new_rotation);
            return rotated_array;
        }
        else
            return NULL;
    }

        int reduce_rotations(const int array_size, const int rotation)
        {
            if (array_size > 1)
                return rotation >= array_size ? rotation % array_size : rotation;
            else
                return 0;
        }

        int* rotate_elements(const int* array, const int array_size, const int rotation)
        {
            int *new_array = (int*) calloc(array_size, sizeof(int));

            memcpy(new_array, &array[array_size - rotation], rotation * sizeof(*array));
            memcpy(new_array + rotation, array, (array_size - rotation) * sizeof(*array));

            return new_array;
        }
