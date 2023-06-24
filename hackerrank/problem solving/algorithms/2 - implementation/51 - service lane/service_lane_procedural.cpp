// Source: https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> find_maximum_affordable_widths_vehicles_while_read_test_cases(const int n_test_cases, const vector<int>& width_measurements);
    int maximum_affordable_width_vehicle_in_range(const vector<int>& width_measurements, const pair<int, int>& point_pair);

int main()
{
    int n_width_measurements, n_test_cases;
    cin >> n_width_measurements >> n_test_cases;

    vector<int> width_measurements(n_width_measurements);
    ranges::generate(width_measurements, []{int element; cin >> element; return element;});

    vector<int> maximum_affordable_widths_vehicles {find_maximum_affordable_widths_vehicles_while_read_test_cases(n_test_cases, width_measurements)};

    ranges::for_each(maximum_affordable_widths_vehicles, [](const int& element){cout << element << "\n";});

    return 0;
}

    vector<int> find_maximum_affordable_widths_vehicles_while_read_test_cases(const int n_test_cases, const vector<int>& width_measurements)
    {
        vector<int> maximum_affordable_widths_vehicles(n_test_cases);

        for (pair<int, int> point_pair {0, 0}; auto& maximum_affordable_width_vehicle : maximum_affordable_widths_vehicles) {
            cin >> point_pair.first >> point_pair.second;
            maximum_affordable_width_vehicle = {maximum_affordable_width_vehicle_in_range(width_measurements, point_pair)};
        }

        return maximum_affordable_widths_vehicles;
    }

        int maximum_affordable_width_vehicle_in_range(const vector<int>& width_measurements, const pair<int, int>& point_pair)
        {
            return *min_element(width_measurements.begin() + point_pair.first, width_measurements.begin() + point_pair.second + 1);
        }
