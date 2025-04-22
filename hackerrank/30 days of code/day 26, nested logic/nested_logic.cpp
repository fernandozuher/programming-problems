// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true
// C++20

#include <chrono>
#include <iostream>

using namespace std;
using date = chrono::year_month_day;

date read_date();

class Fine_on_delay {
public:
    Fine_on_delay(const date& returned_real_date, const date& due_date): returned_real_date{returned_real_date},
                                                                         due_date{due_date},
                                                                         fine_value{calculate_fine()} {}

    int fine() const
    {
        return fine_value;
    }

private:
    constexpr static int fine_per_year{10000};
    constexpr static int fine_per_month{500};
    constexpr static int fine_per_day{15};

    date returned_real_date, due_date;
    int fine_value;

    int calculate_fine() const
    {
        int fine{late_by_year()};
        if (fine)
            return fine;

        fine = late_by_month();
        if (fine)
            return fine;

        return late_by_day();
    }

    int late_by_year() const
    {
        if (returned_real_date.year() > due_date.year())
            return fine_per_year;
        return 0;
    }

    int late_by_month() const
    {
        if (returned_real_date.year() == due_date.year() && returned_real_date.month() > due_date.month())
            return static_cast<int>((returned_real_date.month() - due_date.month()).count()) * fine_per_month;
        return 0;
    }

    int late_by_day() const
    {
        if (returned_real_date.year() == due_date.year() && returned_real_date.month() == due_date.month() &&
            returned_real_date.day() > due_date.day())
            return static_cast<int>((returned_real_date.day() - due_date.day()).count()) * fine_per_day;
        return 0;
    }
};

int main()
{
    auto returned_real_date{read_date()};
    auto due_date{read_date()};
    if (returned_real_date <= due_date)
        cout << 0;
    else
        cout << Fine_on_delay{returned_real_date, due_date}.fine();
    return 0;
}

date read_date()
{
    int day, month, year;
    cin >> day >> month >> year;
    return {chrono::year{year}, chrono::month(month), chrono::day(day)};
}
