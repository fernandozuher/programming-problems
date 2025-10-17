// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

#include <stdio.h>

typedef struct {
    int entry;
    int exit;
} point_pair;

void read_numbers(int *arr, int n);
int max_affordable_width_vehicle_in_range(const int *width_measurements, const point_pair *point);

int main()
{
    int n_widths, n_points;
    scanf("%d %d", &n_widths, &n_points);
    int widths[n_widths];
    read_numbers(widths, n_widths);

    for (int i = 0; i < n_points; ++i) {
        point_pair point;
        scanf("%d %d", &point.entry, &point.exit);
        printf("%d\n", max_affordable_width_vehicle_in_range(widths, &point));
    }

    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

int max_affordable_width_vehicle_in_range(const int *width_measurements, const point_pair *point)
{
    int min = width_measurements[point->entry];
    for (int i = point->entry; i <= point->exit; ++i)
        min = min < width_measurements[i] ? min : width_measurements[i];
    return min;
}
