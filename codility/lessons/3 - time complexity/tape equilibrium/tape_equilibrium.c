// Source: https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/

#include <stdlib.h>

int find_minimum_difference_between_two_parts_array(const int ARRAY[], const int SIZE);
    int sum_array_elements(const int ARRAY[], const int SIZE);


int solution(const int ARRAY[], const int SIZE) {
    const int MINIMUM_DIFFERENCE_BETWEEN_PARTS = find_minimum_difference_between_two_parts_array(ARRAY, SIZE);
    return MINIMUM_DIFFERENCE_BETWEEN_PARTS;
}

    int find_minimum_difference_between_two_parts_array(const int ARRAY[], const int SIZE) {
        int first_part = ARRAY[0];
        int second_part = sum_array_elements(ARRAY, SIZE) - first_part;
        int minimumDifferenceBetweenParts = abs(first_part - second_part);

        for (int i = 1; i < SIZE - 1; i++) {
            first_part += ARRAY[i];
            second_part -= ARRAY[i];
            const int CURRENT_MINIMUM = abs(first_part - second_part);

            if (minimumDifferenceBetweenParts > CURRENT_MINIMUM)
                minimumDifferenceBetweenParts = CURRENT_MINIMUM;
        }

        return minimumDifferenceBetweenParts;
    }

        int sum_array_elements(const int ARRAY[], const int SIZE) {
            int sum = 0;
            for (int i = 0; i < SIZE; sum += ARRAY[i++]);
            return sum;
        }
        