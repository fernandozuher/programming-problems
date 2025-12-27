// https://www.hackerrank.com/challenges/flatland-space-stations/problem?isFullScreen=true
// C++23

import std;
using namespace std;

vector<int> read_numbers(int n);
int max_distance_from_space_station(int last_city, const vector<int>& stations);

int main()
{
    int n_cities, n_stations;
    cin >> n_cities >> n_stations;
    int last_city{ n_cities - 1 };

    vector stations{ read_numbers(n_stations) };
    ranges::sort(stations);
    println("{}", max_distance_from_space_station(last_city, stations));

    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

int max_distance_from_space_station(int last_city, const vector<int>& stations)
{
    int max_dist{ stations.front() };

    for (auto x : stations | views::slide(2)) {
        int gap{ (x[1] - x[0]) / 2 };
        max_dist = max(max_dist, gap);
    }

    return max(max_dist, last_city - stations.back());
}
