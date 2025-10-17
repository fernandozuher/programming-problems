// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> read_numbers(int n);
int max_affordable_width_vehicle_in_range(const vector<int>& width_measurements, const pair<int, int>& point);

int main()
{
    int n_widths, n_points;
    cin >> n_widths >> n_points;
    vector widths{read_numbers(n_widths)};

    for (int i{}; i < n_points; ++i) {
        pair<int, int> point;
        cin >> point.first >> point.second;
        cout << max_affordable_width_vehicle_in_range(widths, point) << '\n';
    }

    return 0;
}

vector<int> read_numbers(int n)
{
    vector<int> arr(n);
    for (auto& x : arr)
        cin >> x;
    return arr;
}

int max_affordable_width_vehicle_in_range(const vector<int>& width_measurements, const pair<int, int>& point)
{
    return *min_element(width_measurements.begin() + point.first, width_measurements.begin() + point.second + 1);
}
