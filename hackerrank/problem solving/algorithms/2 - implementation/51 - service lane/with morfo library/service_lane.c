// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"

typedef struct {
    int entry;
    int exit;
} segment_pair;

int min_width_in_segment(const int *widths, const segment_pair *segment);

int main()
{
    int n = morfo_read(int);
    int t = morfo_read(int);
    int *widths = morfo_read_n_alloc(int, n);

    for (int i = 0; i < t; ++i) {
        segment_pair segment;
        segment.entry = morfo_read(int);
        segment.exit = morfo_read(int);
        printf("%d\n", min_width_in_segment(widths, &segment));
    }

    free(widths);
    return 0;
}

// n: length of widths
// T: O(n)
// S: O(1) extra space
int min_width_in_segment(const int *widths, const segment_pair *segment)
{
    int min = widths[segment->entry];
    for (int i = segment->entry; i <= segment->exit; ++i)
        min = min < widths[i] ? min : widths[i];
    return min;
}
