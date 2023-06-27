// Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

int* read_an_int_array(const int size);
int find_max_distance_from_space_station(const int n_cities, int* cities_with_space_station, const int size);
    int compare (const void* a, const void* b);
    int calculate_distance_between_cities(const int city_with_space_station, const int previous_city);
    bool has_last_city_space_station(const int last_city_with_space_station, const int last_city);
    int calculate_distance_of_last_city(const int last_city_with_space_station, const int last_city);

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

    int find_max_distance_from_space_station(const int n_cities, int* cities_with_space_station, const int size)
    {
        qsort(cities_with_space_station, size, sizeof(int), compare);
        const int first_city = 0;
        int max_distance = cities_with_space_station[0] - first_city;

        for (int i = 1, previous_city = cities_with_space_station[0]; i < size; ++i) {
            const int distance = calculate_distance_between_cities(cities_with_space_station[i], previous_city);
            max_distance = max_distance >= distance ? max_distance : distance;
            previous_city = cities_with_space_station[i];
        }

        const int last_city = n_cities - 1;
        const int last_city_with_space_station = cities_with_space_station[size - 1];
        if (!has_last_city_space_station(last_city, last_city_with_space_station)) {
            const int distance = calculate_distance_of_last_city(last_city, last_city_with_space_station);
            max_distance = max_distance >= distance ? max_distance : distance;
        }

        return max_distance;
    }

        int compare (const void* a, const void* b)
        {
            return (*(int*) a - *(int*) b);
        }

        int calculate_distance_between_cities(const int city_with_space_station, const int previous_city)
        {
            return (city_with_space_station - previous_city) / 2;
        }

        bool has_last_city_space_station(const int last_city, const int last_city_with_space_station)
        {
            return last_city == last_city_with_space_station;
        }

        int calculate_distance_of_last_city(const int last_city, const int last_city_with_space_station)
        {
            return last_city - last_city_with_space_station;
        }
