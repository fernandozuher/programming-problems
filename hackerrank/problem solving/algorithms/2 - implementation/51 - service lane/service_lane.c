// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

#include <stdio.h>
#include <limits.h>

typedef struct {
    int entry;
    int exit;
} point_pair;

int maximum_affordable_width_vehicle_in_range(const int width_measurements[], const point_pair point);

int main()
{
    int n_width_measurements, n;
    scanf("%d %d", &n_width_measurements, &n);
    int width_measurements[n_width_measurements];
    for (int i = 0; i < n_width_measurements; scanf("%d", &width_measurements[i++]));

    int maximum_affordable_widths_vehicles[n];
    for (int i = 0; i < n; ++i) {
        point_pair point;
        scanf("%d %d", &point.entry, &point.exit);
        maximum_affordable_widths_vehicles[i] = maximum_affordable_width_vehicle_in_range(width_measurements, point);
    }

    for (int i = 0; i < n; ++i)
        printf("%d\n", maximum_affordable_widths_vehicles[i]);

    return 0;
}

    int maximum_affordable_width_vehicle_in_range(const int width_measurements[], const point_pair point)
    {
        int min = INT_MAX;
        for (int i = point.entry; i <= point.exit; ++i)
            min = min < width_measurements[i] ? min : width_measurements[i];
        return min;
    }
