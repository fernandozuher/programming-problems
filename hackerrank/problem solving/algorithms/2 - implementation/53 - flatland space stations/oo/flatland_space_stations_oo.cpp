// Source: https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Flatland_Space_Stations
{
private:
    int n_cities;
    vector<int> cities_with_space_station;
    int max_distance_from_space_station;

    void find_max_distance_from_space_station()
    {
        for (int city_i {0}; city_i < this->n_cities; ++city_i) {
            const int distance {find_min_distance_between_city_and_nearest_space_station(city_i)};
            this->max_distance_from_space_station = {max(this->max_distance_from_space_station, distance)};
        }
    }

        int find_min_distance_between_city_and_nearest_space_station(const int city_i) const
        {
            const int element {find_element_or_nearest(city_i, this->cities_with_space_station)};
            const int min_distance_between_city_and_nearest_space_station {abs(city_i - element)};
            return min_distance_between_city_and_nearest_space_station;
        }

            int find_element_or_nearest(const int n, const vector<int>& array) const
            {
                int max {static_cast<int>(array.size() - 1)};
                int min {0};

                int min_distance {INT_MAX};
                int nearest_element {n};

                while (min <= max) {
                    const int mid {static_cast<int>((min + max) / 2)};

                    const int distance {abs(array.at(mid) - n)};
                    if (distance < min_distance) {
                        nearest_element = {array.at(mid)};
                        min_distance = {distance};
                    }

                    if (array.at(mid) == n)
                        return n;
                    else if (array.at(mid) > n)
                        max = {mid - 1};
                    else
                        min = {mid + 1};
                }

                return nearest_element;
            }
public:
    Flatland_Space_Stations(const int n_cities, const vector<int>& cities_with_space_station)
        : n_cities{n_cities}, cities_with_space_station{cities_with_space_station},
          max_distance_from_space_station{0}
    {
        ranges::sort(this->cities_with_space_station);
        find_max_distance_from_space_station();
    }

    int get_max_distance_from_space_station() const
    {
        return max_distance_from_space_station;
    }
};

int main()
{
    int n_cities, n_cities_with_space_station;
    cin >> n_cities >> n_cities_with_space_station;

    vector<int> cities_with_space_station(n_cities_with_space_station);
    ranges::generate(cities_with_space_station, [] {int element; cin >> element; return element;});

    const Flatland_Space_Stations obj {n_cities, cities_with_space_station};
    cout << obj.get_max_distance_from_space_station() << "\n";

    return 0;
}
