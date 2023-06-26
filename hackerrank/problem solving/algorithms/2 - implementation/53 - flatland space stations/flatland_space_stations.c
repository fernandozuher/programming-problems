// Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* read_an_int_array(const int size);
int find_max_distance_from_space_station(const int n_cities, const int* cities_with_space_station, const int size);
    int find_min_distance_between_current_city_and_nearest_space_station(const int city_i, const int* cities_with_space_station, const int size);

int main()
{
    int n_cities, n_cities_with_space_station;
    scanf("%d %d", &n_cities, &n_cities_with_space_station);

    int* cities_with_space_station = read_an_int_array(n_cities);
    printf("%d\n", find_max_distance_from_space_station(n_cities, cities_with_space_station, n_cities_with_space_station));

    free(cities_with_space_station);
    cities_with_space_station = NULL;

    return 0;
}

    int* read_an_int_array(const int size)
    {
        int* array = (int*) calloc(size, sizeof(int));
        for (int i = 0; i < size; ++i)
            scanf("%d", &array[i]);
        return array;
    }

    int find_max_distance_from_space_station(const int n_cities, const int* cities_with_space_station, const int size)
    {
        int max_distance = 0;

        for (int city_i = 0; city_i < n_cities; ++city_i) {
            const int distance = find_min_distance_between_current_city_and_nearest_space_station(city_i, cities_with_space_station, size);
            max_distance = max_distance >= distance ? max_distance : distance;
        }

        return max_distance;
    }

        int find_min_distance_between_current_city_and_nearest_space_station(const int city_i, const int* cities_with_space_station, const int size)
        {
            int min_distance = INT_MAX;

            for (int i = 0; i < size; ++i) {
                const int distance = abs(cities_with_space_station[i] - city_i);
                min_distance = min_distance <= distance ? min_distance : distance;
            }

            return min_distance;
        }
