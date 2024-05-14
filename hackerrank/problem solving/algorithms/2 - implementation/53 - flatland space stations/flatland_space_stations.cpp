// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true
// From C++20

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

class Flatland_Space_Stations {
    int n_cities;
    vector<int> cities_with_space_station;
    int max_distance_from_space_station;

public:
    Flatland_Space_Stations(int n_cities, const vector<int>& cities_with_space_station);
    [[nodiscard]] int maximum_distance_from_space_station() const;
    void find_max_distance_from_space_station();
};

    Flatland_Space_Stations::Flatland_Space_Stations(const int n_cities, const vector<int>& cities_with_space_station)
        : n_cities{n_cities}, cities_with_space_station{cities_with_space_station},
          max_distance_from_space_station{cities_with_space_station.front()} {}

    [[nodiscard]] int Flatland_Space_Stations::maximum_distance_from_space_station() const
    {
        return max_distance_from_space_station;
    }

    void Flatland_Space_Stations::find_max_distance_from_space_station()
    {
        for (auto previous_city {cities_with_space_station.front()}; const auto city_with_space_station :
                cities_with_space_station | views::drop(1)) {
            int distance_between_cities {(city_with_space_station - previous_city) / 2};
            max_distance_from_space_station = max(max_distance_from_space_station, distance_between_cities);
            previous_city = city_with_space_station;
        }

        if (bool has_last_city_space_station {n_cities - 1 == cities_with_space_station.back()};
            !has_last_city_space_station) {
            int distance_of_last_city {n_cities - 1 - cities_with_space_station.back()};
            max_distance_from_space_station = max(max_distance_from_space_station, distance_of_last_city);
        }
    }

int main()
{
    int n_cities, n_cities_with_space_station;
    cin >> n_cities >> n_cities_with_space_station;

    vector<int> cities_with_space_station(n_cities_with_space_station);
    ranges::generate(cities_with_space_station, []{int x; cin >> x; return x;});
    ranges::sort(cities_with_space_station);

    Flatland_Space_Stations obj{n_cities, cities_with_space_station};
    obj.find_max_distance_from_space_station();
    cout << obj.maximum_distance_from_space_station();

    return 0;
}
