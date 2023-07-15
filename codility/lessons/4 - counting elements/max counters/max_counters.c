// Source: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

#include <stdbool.h>
#include <string.h>

void reinit_counters(int* counters, const int size);

struct Results solution(int n_counters, int array[], int size_array)
{
    bool found_max_counter = false;
    int max = 0, size_counters = n_counters + 1;
    int *counters = (int*) calloc(size_counters, sizeof(int));

    for (int i = 0, current_max = 0; i < size_array; ++i)

        if (array[i] < size_counters) {
            if (found_max_counter) {
                reinit_counters(counters, size_counters);
                found_max_counter = false;
                current_max = 0;
            }
            if (++counters[array[i]] > current_max)
                current_max++;
        }
        else if (!found_max_counter) {
            max += current_max;
            found_max_counter = true;
        }

    if (found_max_counter)
        for (int i = 1; i < size_counters; counters[i++] = max);
    else if (max)
        for (int i = 1; i < size_counters; counters[i++] += max);

    return (struct Results) {++counters, n_counters};
}

    void reinit_counters(int* counters, const int size)
    {
        memset(counters, 0, size * sizeof(int));
    }
