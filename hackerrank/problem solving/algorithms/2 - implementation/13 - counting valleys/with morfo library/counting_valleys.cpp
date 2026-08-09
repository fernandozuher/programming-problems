// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true
// C++23

import morfo;
import std;
using namespace std;

int counting_valleys(string_view steps);

int main()
{
    morfo::skip_input_ln();
    string steps = morfo::read();
    cout << counting_valleys(steps);
    return 0;
}

// n: length of steps
// T: O(n)
// S: O(1) extra space
int counting_valleys(string_view steps)
{
    int valleys{};

    for (int current_altitude{}; auto step : steps) {
        bool was_below_sea_level{ current_altitude < 0 };
        current_altitude += step == 'D' ? -1 : 1;
        bool is_in_sea_level_from_valley{ was_below_sea_level && current_altitude == 0 };
        valleys += is_in_sea_level_from_valley;
    }

    return valleys;
}
