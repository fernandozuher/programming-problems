// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true
// From C23

#include <stdio.h>
#include <stdlib.h>

int *read_int_array(int n);
int find_max_distance_from_space_station(int n_cities, const int *cities_with_space_station, int n);
int compare(const void *a, const void *b);

int main()
{
    int n_cities, n_cities_with_space_station;
    scanf("%d %d", &n_cities, &n_cities_with_space_station);

    int *cities_with_space_station = read_int_array(n_cities_with_space_station);
    qsort(cities_with_space_station, n_cities_with_space_station, sizeof(int), compare);

    printf("%d\n", find_max_distance_from_space_station(n_cities, cities_with_space_station,
            n_cities_with_space_station));

    free(cities_with_space_station);
    cities_with_space_station = NULL;

    return 0;
}

    int *read_int_array(const int n)
    {
        int *array = (int*) malloc(n * sizeof(int));
        for (int i = 0; i < n; ++i)
            scanf("%d", &array[i]);
        return array;
    }

    int compare(const void *a, const void *b)
    {
        return (*(int *) a - * (int *) b);
    }

    int find_max_distance_from_space_station(const int n_cities, const int *const cities_with_space_station, const int n_cities_with_space_station)
    {
        int max_distance = cities_with_space_station[0];

        for (int i = 1, previous_city = cities_with_space_station[0]; i < n_cities_with_space_station; ++i) {
            int distance_between_cities = (cities_with_space_station[i] - previous_city) / 2;
            max_distance = max_distance >= distance_between_cities ? max_distance : distance_between_cities;
            previous_city = cities_with_space_station[i];
        }

        int last_city = n_cities - 1;
        int last_city_with_space_station = cities_with_space_station[n_cities_with_space_station - 1];
        bool has_last_city_space_station = n_cities - 1 == cities_with_space_station[n_cities_with_space_station - 1];

        if (!has_last_city_space_station) {
            int distance_of_last_city = n_cities - 1 - cities_with_space_station[n_cities_with_space_station - 1];
            max_distance = max_distance >= distance_of_last_city ? max_distance : distance_of_last_city;
        }

        return max_distance;
    }
