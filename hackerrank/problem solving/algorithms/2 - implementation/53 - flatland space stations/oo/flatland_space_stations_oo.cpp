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
        const int first_city {0};
        this->max_distance_from_space_station = {this->cities_with_space_station.front() - first_city};

        for (int i {1}, previous_city {this->cities_with_space_station.front()}, size {static_cast<int>(this->cities_with_space_station.size())}; i < size; ++i) {
            const int distance {this->calculate_distance_between_cities(this->cities_with_space_station.at(i), previous_city)};
            this->max_distance_from_space_station = {max(this->max_distance_from_space_station, distance)};
            previous_city = {this->cities_with_space_station.at(i)};
        }

        if (!this->has_last_city_space_station()) {
            const int distance {this->calculate_distance_of_last_city()};
            this->max_distance_from_space_station = {max(this->max_distance_from_space_station, distance)};
        }
    }

        int calculate_distance_between_cities(const int city_with_space_station, const int previous_city) const
        {
            return (city_with_space_station - previous_city) / 2;
        }

        bool has_last_city_space_station() const
        {
            return this->n_cities-1 == this->cities_with_space_station.back();
        }

        int calculate_distance_of_last_city() const
        {
            return this->n_cities-1 - this->cities_with_space_station.back();
        }

public:
    Flatland_Space_Stations(const int n_cities, const vector<int>& cities_with_space_station)
        : n_cities{n_cities}, cities_with_space_station{cities_with_space_station},
          max_distance_from_space_station{0}
    {
        ranges::sort(this->cities_with_space_station);
        this->find_max_distance_from_space_station();
    }

    int get_max_distance_from_space_station() const
    {
        return this->max_distance_from_space_station;
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
