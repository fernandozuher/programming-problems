// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int max_distance_from_space_station(int last_city, const vector<int>& stations);

int main()
{
    int n_cities = morfo::read();
    int n_stations = morfo::read();
    int last_city{ n_cities - 1 };

    vector<int> stations = morfo::read(n_stations);
    ranges::sort(stations);
    println("{}", max_distance_from_space_station(last_city, stations));

    return 0;
}

// n: length of stations
// T: O(n)
// S: O(1) extra space
int max_distance_from_space_station(int last_city, const vector<int>& stations)
{
    int max_dist{ stations.front() };

    for (auto x : stations | views::slide(2)) {
        int gap{ (x[1] - x[0]) / 2 };
        max_dist = max(max_dist, gap);
    }

    return max(max_dist, last_city - stations.back());
}
