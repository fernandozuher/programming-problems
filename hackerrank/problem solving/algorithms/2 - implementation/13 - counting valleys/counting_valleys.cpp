// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

#include <algorithm>
#include <iostream>

using namespace std;

int counting_valleys(const string_view& steps);
bool is_in_sea_level_from_valley(bool was_travessing_a_valley, int current_altitude);

int main()
{
    int n;
    string array;
    cin >> n >> array;
    cout << counting_valleys(array);
    return 0;
}

int counting_valleys(const string_view& steps)
{
    const auto lambda{
        [](const auto step) {
            static int current_altitude{};
            bool was_travessing_a_valley{current_altitude < 0};
            current_altitude += step == 'D' ? -1 : 1;
            return is_in_sea_level_from_valley(was_travessing_a_valley, current_altitude);
        }
    };
    return static_cast<int>(ranges::count_if(steps, lambda));
}

bool is_in_sea_level_from_valley(const bool was_travessing_a_valley, const int current_altitude)
{
    return was_travessing_a_valley && !current_altitude;
}
