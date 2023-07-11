// Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

#include <stdlib.h>

int sum_array_elements(const int* array, const int size);

int solution(const int* array, const int size)
{
    int first_part = array[0];
    int second_part = sum_array_elements(array, size) - first_part;
    int minimum_difference_between_parts = abs(first_part - second_part);

    for (int i = 1, new_size = size - 1; i < new_size; ++i) {
        first_part += array[i];
        second_part -= array[i];
        const int current_minimum = abs(first_part - second_part);

        if (minimum_difference_between_parts > current_minimum)
            minimum_difference_between_parts = current_minimum;
    }

    return minimum_difference_between_parts;
}

    int sum_array_elements(const int* array, const int size)
    {
        int sum = 0;
        for (int i = 0; i < size; sum += array[i++]);
        return sum;
    }
