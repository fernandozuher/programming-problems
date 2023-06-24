// Source: https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct point_pair {
    int entry;
    int exit;
};

int* read_an_int_array(const int size);
int* find_maximum_affordable_widths_vehicles_while_read_test_cases(const int n_test_cases, const int* width_measurements);
    int maximum_affordable_width_vehicle_in_range(const int* width_measurements, const struct point_pair point);

int main()
{
    int n_width_measurements, n_test_cases;
    scanf("%d %d", &n_width_measurements, &n_test_cases);
    int* width_measurements = read_an_int_array(n_width_measurements);

    int* maximum_affordable_widths_vehicles = find_maximum_affordable_widths_vehicles_while_read_test_cases(n_test_cases, width_measurements);

    for (int i = 0; i < n_test_cases; ++i) printf("%d\n", maximum_affordable_widths_vehicles[i]);

    free(width_measurements);
    width_measurements = NULL;

    free(maximum_affordable_widths_vehicles);
    maximum_affordable_widths_vehicles = NULL;

    return 0;
}

    int* read_an_int_array(const int size)
    {
        int *array = (int*) calloc(size, sizeof(int));
        for (int i = 0; i < size; scanf("%d", &array[i++]));
        return array;
    }

    int* find_maximum_affordable_widths_vehicles_while_read_test_cases(const int n_test_cases, const int* width_measurements)
    {
        int* maximum_affordable_widths_vehicles = (int*) calloc(n_test_cases, sizeof(int));

        for (int i = 0; i < n_test_cases; ++i) {
            struct point_pair point;
            scanf("%d %d", &point.entry, &point.exit);
            maximum_affordable_widths_vehicles[i] = maximum_affordable_width_vehicle_in_range(width_measurements, point);
        }

        return maximum_affordable_widths_vehicles;
    }

        int maximum_affordable_width_vehicle_in_range(const int* width_measurements, const struct point_pair point)
        {
            int min = INT_MAX;
            for (int i = point.entry; i <= point.exit; ++i)
                min = min < width_measurements[i] ? min : width_measurements[i];
            return min;
        }
