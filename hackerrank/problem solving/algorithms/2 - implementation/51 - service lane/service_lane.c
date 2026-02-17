// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

#include <stdio.h>

typedef struct {
    int entry;
    int exit;
} segment_pair;

void read_numbers(int *arr, int n);
int min_width_in_segment(const int *widths, const segment_pair *segment);

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    int widths[n];
    read_numbers(widths, n);

    for (int i = 0; i < t; ++i) {
        segment_pair segment;
        scanf("%d %d", &segment.entry, &segment.exit);
        printf("%d\n", min_width_in_segment(widths, &segment));
    }

    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

// n: length of array widths
// T: O(n)
// S: O(1) extra space
int min_width_in_segment(const int *widths, const segment_pair *segment)
{
    int min = widths[segment->entry];
    for (int i = segment->entry; i <= segment->exit; ++i)
        min = min < widths[i] ? min : widths[i];
    return min;
}
