// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

#include <iostream>

using namespace std;

string time_conversion(const string& time);
bool is_first_period_of_day(const string& day_period);
string change_hour(const string& hour, string time);
string convert_pm_hour_to_24_h(const string& hour);

int main()
{
    string time;
    cin >> time;
    cout << time_conversion(time);

    return 0;
}

    string time_conversion(const string& time)
    {
        string converted_time {time.substr(0, 8)};
        string hour {time.substr(0, 2)};
        string day_period {time.substr(8, 1)};

        if (hour == "12") {
            if (is_first_period_of_day(day_period)) {
                string midnight {"00"};
                converted_time = change_hour(midnight, converted_time);
            }
        }
        else if (!is_first_period_of_day(day_period)) {
            string new_hour {convert_pm_hour_to_24_h(hour)};
            converted_time = change_hour(new_hour, converted_time);
        }

        return converted_time;
    }

        bool is_first_period_of_day(const string& day_period)
        {
            return day_period == "A";
        }

        string change_hour(const string& hour, string time)
        {
            time.replace(0, 2, hour);
            return time;
        }

        string convert_pm_hour_to_24_h(const string& hour)
        {
            int new_hour {stoi(hour)};
            new_hour += 12;
            return to_string(new_hour);
        }
