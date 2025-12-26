// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

#include <stdio.h>

typedef struct {
    int entry;
    int exit;
} segment_pair;

void read_numbers(int *arr, unsigned n);
int min_width_in_segment(const int *width_measurements, const segment_pair *segment);

int main()
{
    unsigned n, t;
    scanf("%u %u", &n, &t);
    int widths[n];
    read_numbers(widths, n);

    while (t--) {
        segment_pair segment;
        scanf("%d %d", &segment.entry, &segment.exit);
        printf("%d\n", min_width_in_segment(widths, &segment));
    }

    return 0;
}

void read_numbers(int *arr, unsigned n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

int min_width_in_segment(const int *width_measurements, const segment_pair *segment)
{
    int min = width_measurements[segment->entry];
    for (int i = segment->entry; i <= segment->exit; ++i)
        min = min < width_measurements[i] ? min : width_measurements[i];
    return min;
}
