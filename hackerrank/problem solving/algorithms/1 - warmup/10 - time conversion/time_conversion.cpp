// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true
// C++23

import std;
using namespace std;

string to_24_hour_time(string_view time);
string gen_new_hour(string_view day_period, string_view hour);

int main()
{
    string time;
    cin >> time;
    cout << to_24_hour_time(time);
    return 0;
}

// T: O(1)
// S: O(1) extra space
string to_24_hour_time(string_view time)
{
    string hour_24{ time.substr(0, 8) };
    string_view hour{ time.substr(0, 2) };
    string_view day_period{ time.substr(8, 1) };

    if ((hour == "12" && day_period == "A") || (hour != "12" && day_period == "P")) {
        string new_hour = gen_new_hour(day_period, hour);
        hour_24 = hour_24.replace(0, 2, new_hour);
    }

    return hour_24;
}

string gen_new_hour(string_view day_period, string_view hour)
{
    if (day_period == "A")
        return "00"s;
    int new_hour{ stoi(string(hour)) };
    new_hour += 12;
    return to_string(new_hour);
}
