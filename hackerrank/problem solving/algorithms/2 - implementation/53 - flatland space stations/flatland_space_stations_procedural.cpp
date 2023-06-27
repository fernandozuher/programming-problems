// Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int find_max_distance_from_space_station(const int n_cities, vector<int>& cities_with_space_station);
    int calculate_distance_between_cities(const int city_with_space_station, const int previous_city);
    bool has_last_city_space_station(const int last_city_with_space_station, const int last_city);
    int calculate_distance_of_last_city(const int last_city_with_space_station, const int last_city);

int main()
{
    int n_cities, n_cities_with_space_station;
    cin >> n_cities >> n_cities_with_space_station;

    vector<int> cities_with_space_station(n_cities_with_space_station);
    ranges::generate(cities_with_space_station, [] {int element; cin >> element; return element;});

    cout << find_max_distance_from_space_station(n_cities, cities_with_space_station) << "\n";

    return 0;
}

    int find_max_distance_from_space_station(const int n_cities, vector<int>& cities_with_space_station)
    {
        ranges::sort(cities_with_space_station);
        const int first_city {0};
        int max_distance {cities_with_space_station.front() - first_city};

        for (int i {1}, previous_city {cities_with_space_station.front()}, size {static_cast<int>(cities_with_space_station.size())}; i < size; ++i) {
            const int distance {calculate_distance_between_cities(cities_with_space_station.at(i), previous_city)};
            max_distance = {max(max_distance, distance)};
            previous_city = {cities_with_space_station.at(i)};
        }

        if (int last_city {n_cities - 1}, last_city_with_space_station {cities_with_space_station.back()}; !has_last_city_space_station(last_city, last_city_with_space_station)) {
            const int distance {calculate_distance_of_last_city(last_city, last_city_with_space_station)};
            max_distance = {max(max_distance, distance)};
        }

        return max_distance;
    }

        int calculate_distance_between_cities(const int city_with_space_station, const int previous_city)
        {
            return (city_with_space_station - previous_city) / 2;
        }

        bool has_last_city_space_station(const int last_city, const int last_city_with_space_station)
        {
            return last_city_with_space_station == last_city;
        }

        int calculate_distance_of_last_city(const int last_city, const int last_city_with_space_station)
        {
            return last_city - last_city_with_space_station;
        }
