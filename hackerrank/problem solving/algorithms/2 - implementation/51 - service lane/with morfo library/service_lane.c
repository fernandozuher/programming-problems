// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include "morfo/io.h"
#include "morfo/math.h"

typedef struct {
    int entry;
    int exit;
} segment_pair;

int min_width_in_segment(const int *widths, const segment_pair *segment);

int main()
{
    int n, t;
    morfo_read_many(&n, &t);
    int *widths = morfo_read_n_alloc(int, n);

    for (int i = 0; i < t; ++i) {
        segment_pair segment;
        morfo_read_many(&segment.entry, &segment.exit);
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
    return morfo_min(widths + segment->entry, (size_t) (segment->exit - segment->entry + 1));
}
