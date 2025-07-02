// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

#include <iostream>

using namespace std;

constexpr int TRANSITION_YEAR{1918};

string calculate_date_of_256th_day(int year);
bool is_leap_year(int year);
bool is_leap_julian_year(int year);
bool is_leap_gregorian_year(int year);

int main()
{
    int year;
    cin >> year;
    cout << calculate_date_of_256th_day(year);
    return 0;
}

string calculate_date_of_256th_day(int year)
{
    string day;
    if (year == TRANSITION_YEAR)
        day = "26"s;
    else
        day = is_leap_year(year) ? "12"s : "13"s;
    return day + ".09."s + to_string(year);
}

bool is_leap_year(int year)
{
    if (year < TRANSITION_YEAR)
        return is_leap_julian_year(year);
    if (year > TRANSITION_YEAR)
        return is_leap_gregorian_year(year);
    return false;
}

bool is_leap_julian_year(int year)
{
    return !(year % 4);
}

bool is_leap_gregorian_year(int year)
{
    return !(year % 400) || (!(year % 4) && year % 100);
}
