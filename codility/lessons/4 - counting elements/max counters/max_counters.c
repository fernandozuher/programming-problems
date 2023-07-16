// Source: https://app.codility.com/programmers/lessons/4-counting_elements/max_counters/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void set_default_zero_values(int* counters, const int size, bool *found_max_counter, int *current_max);
struct Results compouse_result(const bool found_max_counter, const int max, int* counters, const int size_counters);

struct Results solution(int n_counters, int array[], int size_array)
{
    bool found_max_counter = false;
    int max = 0, size_counters = n_counters + 1;
    int *counters = (int*) calloc(size_counters, sizeof(int));

    for (int i = 0, current_max = 0; i < size_array; ++i)
        if (array[i] <= n_counters) {
            if (found_max_counter)
                set_default_zero_values(counters, size_counters, &found_max_counter, &current_max);

            if (++counters[array[i]] > current_max)
                current_max++;
        }
        else if (!found_max_counter) {
            max += current_max;
            found_max_counter = true;
        }

    return compouse_result(found_max_counter, max, counters, size_counters);
}

    void set_default_zero_values(int* counters, const int size, bool *found_max_counter, int *current_max)
    {
        memset(counters, 0, size * sizeof(int));
        *found_max_counter = false;
        *current_max = 0;
    }

    struct Results compouse_result(const bool found_max_counter, const int max, int* counters, const int size_counters)
    {
        if (found_max_counter)
            for (int i = 1; i < size_counters; counters[i++] = max);
        else if (max)
            for (int i = 1; i < size_counters; counters[i++] += max);

        return (struct Results) {++counters, size_counters - 1};
    }
