// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true
// C++23

import std;
using namespace std;

string time_conversion(string_view time);

int main()
{
    string time;
    cin >> time;
    cout << time_conversion(time);
    return 0;
}

// T: O(1)
// S: O(1) extra space
string time_conversion(string_view time)
{
    string converted_time{ time.substr(0, 8) };
    string hour{ time.substr(0, 2) };
    string day_period{ time.substr(8, 1) };

    if (hour == "12"s) {
        if (day_period == "A"s) {
            string midnight{ "00"s };
            converted_time.replace(0, 2, midnight);
        }
    }
    else if (day_period == "P"s) {
        int new_hour{ stoi(hour) };
        new_hour += 12;
        converted_time.replace(0, 2, to_string(new_hour));
    }

    return converted_time;
}
