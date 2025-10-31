// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

#include <iostream>

using namespace std;

int counting_valleys(string_view steps);

int main()
{
    int n;
    string steps;
    cin >> n >> steps;
    cout << counting_valleys(steps);
    return 0;
}

int counting_valleys(string_view steps)
{
    int valleys{};

    for (int current_altitude{}; auto step : steps) {
        bool was_below_sea_level{current_altitude < 0};
        current_altitude += step == 'D' ? -1 : 1;
        if (bool is_in_sea_level_from_valley{was_below_sea_level && current_altitude == 0}; is_in_sea_level_from_valley)
            ++valleys;
    }

    return valleys;
}
