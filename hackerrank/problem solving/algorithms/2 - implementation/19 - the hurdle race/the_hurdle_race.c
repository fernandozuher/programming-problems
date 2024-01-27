// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

int* read_int_array(const int n);
int hurdle_race(const int* const hurdles_heights, const int n, const int maximum_height_can_jump);

int main()
{
    int n, maximum_height_can_jump;
    scanf("%d %d", &n, &maximum_height_can_jump);

    int *hurdles_heights = read_int_array(n);
    printf("%d\n", hurdle_race(hurdles_heights, n, maximum_height_can_jump));

    free(hurdles_heights);
    hurdles_heights = NULL;

    return 0;
}

    int* read_int_array(const int n)
    {
        int *array = (int*) calloc(n, sizeof(int));
        for (int i = 0; i < n; scanf("%d", &array[i++]));
        return array;
    }

    int hurdle_race(const int* const hurdles_heights, const int n, const int maximum_height_can_jump)
    {
        int highest_hurdle = hurdles_heights[0];

        for (int i = 1; i < n; ++i)
            if (highest_hurdle < hurdles_heights[i])
                highest_hurdle = hurdles_heights[i];

        return highest_hurdle > maximum_height_can_jump ? highest_hurdle - maximum_height_can_jump : 0;
    }
