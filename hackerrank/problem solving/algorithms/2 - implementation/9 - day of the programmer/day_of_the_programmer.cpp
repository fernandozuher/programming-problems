// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

#include <iostream>

using namespace std;

class Day_Of_The_Programmer {
public:
    explicit Day_Of_The_Programmer(int year);
    string calculate_date_of_256th_day();
    [[nodiscard]] string date() const;

private:
    static constexpr int transition_year{1918};
    int year;
    string date_of_256th_day;

    [[nodiscard]] bool is_leap_year() const;
    [[nodiscard]] bool is_leap_gregorian_year() const;
    [[nodiscard]] bool is_leap_julian_year() const;
};

Day_Of_The_Programmer::Day_Of_The_Programmer(const int year): year{year} {}

string Day_Of_The_Programmer::calculate_date_of_256th_day()
{
    if (year != transition_year)
        date_of_256th_day = is_leap_year() ? "12.09." : "13.09.";
    else
        date_of_256th_day = "26.09.";
    date_of_256th_day += to_string(year);

    return date();
}

bool Day_Of_The_Programmer::is_leap_year() const
{
    return year > transition_year ? is_leap_gregorian_year() : is_leap_julian_year();
}

bool Day_Of_The_Programmer::is_leap_gregorian_year() const
{
    return !(year % 400) || (!(year % 4) && year % 100);
}

bool Day_Of_The_Programmer::is_leap_julian_year() const
{
    return !(year % 4);
}

string Day_Of_The_Programmer::date() const
{
    return date_of_256th_day;
}

//////////////////////////////////////////////////

int main()
{
    int year;
    cin >> year;
    cout << Day_Of_The_Programmer{year}.calculate_date_of_256th_day();
    return 0;
}
