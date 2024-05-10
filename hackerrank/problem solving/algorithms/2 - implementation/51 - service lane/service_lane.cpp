// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_int_array(int n);
vector<int> find_maximum_affordable_widths_vehicles_while_read_test_cases(int n, const vector<int>& width_measurements);
    int maximum_affordable_width_vehicle_in_range(const vector<int>& width_measurements, const pair<int, int>& point_pair);

int main()
{
    int n_width_measurements, n;
    cin >> n_width_measurements >> n;
    for (const int x : find_maximum_affordable_widths_vehicles_while_read_test_cases(n, read_int_array(n_width_measurements)))
        cout << x << '\n';

    return 0;
}

    vector<int> read_int_array(const int n)
    {
        vector<int> array(n);
        ranges::generate(array, []{int x; cin >> x; return x;});
        return array;
    }

    vector<int> find_maximum_affordable_widths_vehicles_while_read_test_cases(
        const int n, const vector<int>& width_measurements)
    {
        vector<int> maximum_affordable_widths_vehicles(n);

        ranges::generate(maximum_affordable_widths_vehicles, [&width_measurements]{
            pair<int, int> point_pair;
            cin >> point_pair.first >> point_pair.second;
            return maximum_affordable_width_vehicle_in_range(width_measurements, point_pair);
        });

        return maximum_affordable_widths_vehicles;
    }

        int maximum_affordable_width_vehicle_in_range(const vector<int>& width_measurements, const pair<int, int>& point_pair)
        {
            return *min_element(width_measurements.begin() + point_pair.first, width_measurements.begin() + point_pair.second + 1);
        }
