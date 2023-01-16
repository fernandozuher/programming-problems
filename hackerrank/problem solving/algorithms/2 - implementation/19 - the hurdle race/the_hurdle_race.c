// Source: https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_line_as_int_array(const int n);
int* free_pointer_and_return_null(int* pointer);
int hurdle_race(const int *hurdles_heights, const int n, const int maximum_height_can_jump);


int main() {
    int *input_line = read_line_as_int_array(2);
    const int n = input_line[0];
    const int maximum_height_can_jump = input_line[1];
    input_line = free_pointer_and_return_null(input_line);

    int *hurdles_heights = read_line_as_int_array(n);

    const int result = hurdle_race(hurdles_heights, n, maximum_height_can_jump);
    input_line = free_pointer_and_return_null(hurdles_heights);

    printf("%d\n", result);

    return 0;
}

    int* read_line_as_int_array(const int n) {
        int *input_line = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &input_line[i]);
        return input_line;
    }

    int* free_pointer_and_return_null(int* pointer) {
        free(pointer);
        return NULL;
    }

    int hurdle_race(const int *hurdles_heights, const int n, const int maximum_height_can_jump) {
        int highest_hurdle = hurdles_heights[0];

        for (int i = 1; i < n; i++)
            if (highest_hurdle < hurdles_heights[i])
                highest_hurdle = hurdles_heights[i];

        const int doses = highest_hurdle > maximum_height_can_jump ? highest_hurdle - maximum_height_can_jump : 0;
        return doses;
    }
