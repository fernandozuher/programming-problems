// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>

void read_numbers(int *arr, int n);
int compare(const void *a, const void *b);
int max_distance_from_space_station(int n_cities, const int *stations, int n_stations);

int main()
{
    int n_cities, n_stations;
    scanf("%d %d", &n_cities, &n_stations);

    int stations[n_stations];
    read_numbers(stations, n_stations);
    qsort(stations, n_stations, sizeof(int), compare);

    printf("%d\n", max_distance_from_space_station(n_cities, stations, n_stations));

    return 0;
}

void read_numbers(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}

int compare(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int max_distance_from_space_station(int n_cities, const int *stations, int n_stations)
{
    int maxDist = stations[0];

    for (int i = 1; i < n_stations; ++i) {
        int gap = (stations[i] - stations[i - 1]) / 2;
        if (maxDist < gap)
            maxDist = gap;
    }

    int lastCity = n_cities - 1;
    int distAfterLast = lastCity - stations[n_stations - 1];
    if (maxDist < distAfterLast)
        maxDist = distAfterLast;

    return maxDist;
}
