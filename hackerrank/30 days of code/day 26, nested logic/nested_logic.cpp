// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true
// C++20

#include <chrono>
#include <iostream>
#include <tuple>

using namespace std;

tuple<chrono::year_month_day, chrono::year_month_day> read_dates();
int calculate_fine(const chrono::year_month_day& returned_real_date, const chrono::year_month_day& due_date);

int main()
{
    auto [returned_real_date, due_date] = read_dates();
    cout << (returned_real_date <= due_date ? 0 : calculate_fine(returned_real_date, due_date));
    return 0;
}

tuple<chrono::year_month_day, chrono::year_month_day> read_dates()
{
    int d1, m1, y1, d2, m2, y2;
    cin >> d1 >> m1 >> y1;
    cin >> d2 >> m2 >> y2;
    return {
        chrono::year_month_day{chrono::year{y1}, chrono::month(m1), chrono::day(d1)},
        chrono::year_month_day{chrono::year{y2}, chrono::month(m2), chrono::day(d2)}
    };
}

int calculate_fine(const chrono::year_month_day& returned_real_date, const chrono::year_month_day& due_date)
{
    constexpr int per_day = 15,
            per_month = 500,
            per_year = 10000;
    if (returned_real_date.year() > due_date.year())
        return per_year;
    if (returned_real_date.year() == due_date.year() && returned_real_date.month() > due_date.month())
        return static_cast<int>((returned_real_date.month() - due_date.month()).count()) * per_month;
    return static_cast<int>((returned_real_date.day() - due_date.day()).count()) * per_day;
}
