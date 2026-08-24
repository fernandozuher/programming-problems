// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include "morfo/collections.h"
#include "morfo/io.h"
#include "morfo/math.h"

int max_distance_from_space_station(int last_city, const int *stations, int n);

int main()
{
    int n_cities, n_stations;
    morfo_read_many(&n_cities, &n_stations);
    int last_city = n_cities - 1;

    int *stations = morfo_read_n_alloc(int, n_stations);
    morfo_sort(stations, (size_t) n_stations);

    printf("%d\n", max_distance_from_space_station(last_city, stations, n_stations));

    free(stations);
    return 0;
}

// n: length of stations
// T: O(n)
// S: O(1) extra space
int max_distance_from_space_station(int last_city, const int *stations, int n)
{
    int max_dist = stations[0];

    for (int i = 1; i < n; ++i) {
        int gap = (stations[i] - stations[i - 1]) / 2;
        max_dist = morfo_max_of(max_dist, gap);
    }

    return morfo_max_of(max_dist, last_city - stations[n - 1]);
}
