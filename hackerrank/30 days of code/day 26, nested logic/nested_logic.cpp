// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true
// C++20

#include <chrono>
#include <iostream>
#include <tuple>

using namespace std;
using date = chrono::year_month_day;

tuple<date, date> read_dates();
int calculate_fine(const date& returned_real_date, const date& due_date);

int main()
{
    auto [returned_real_date, due_date] = read_dates();
    cout << calculate_fine(returned_real_date, due_date);
    return 0;
}

tuple<date, date> read_dates()
{
    int d1, m1, y1, d2, m2, y2;
    cin >> d1 >> m1 >> y1;
    cin >> d2 >> m2 >> y2;

    auto returned_date{date{chrono::year{y1}, chrono::month(m1), chrono::day(d1)}};
    auto due_date{date{chrono::year{y2}, chrono::month(m2), chrono::day(d2)}};
    return {returned_date, due_date};
}

int calculate_fine(const date& returned_real_date, const date& due_date)
{
    constexpr int per_day = 15;
    constexpr int per_month = 500;
    constexpr int per_year = 10000;

    if (returned_real_date <= due_date)
        return 0;

    if (bool is_late_by_year{returned_real_date.year() > due_date.year()}; is_late_by_year)
        return per_year;

    if (bool is_late_by_month{
        returned_real_date.year() == due_date.year() && returned_real_date.month() > due_date.month()
    }; is_late_by_month)
        return static_cast<int>((returned_real_date.month() - due_date.month()).count()) * per_month;

    // else is_late_by_day
    return static_cast<int>((returned_real_date.day() - due_date.day()).count()) * per_day;
}
