// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

#include <iostream>

using namespace std;

class Day_Of_The_Programmer {
public:
    Day_Of_The_Programmer(const int year): year{year}
    {
        find_date_of_256th_day();
    }

    string date() const;

private:
    static const int transition_year {1918};
    int year;
    string date_of_256th_day;

    void find_date_of_256th_day();
        void find_day_month_of_256th_day();
            bool is_leap_year() const;
                bool is_leap_gregorian_year() const;
                bool is_leap_julian_year() const;
};

    string Day_Of_The_Programmer::date() const
    {
        return date_of_256th_day;
    }

    void Day_Of_The_Programmer::find_date_of_256th_day()
    {
        find_day_month_of_256th_day();
        date_of_256th_day.append(to_string(year));
    }

        void Day_Of_The_Programmer::find_day_month_of_256th_day()
        {
            if (year != transition_year)
                date_of_256th_day = is_leap_year() ? "12.09." : "13.09.";
            else
                date_of_256th_day = "26.09.";
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

int main() {
    int year;
    cin >> year;
    Day_Of_The_Programmer obj{year};
    cout << obj.date();

    return 0;
}
