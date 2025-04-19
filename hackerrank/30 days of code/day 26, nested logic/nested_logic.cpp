// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true
// C++20

#include <chrono>
#include <iostream>

using namespace std;
using date = chrono::year_month_day;

date read_date();
int calculate_fine(const date& returned_real_date, const date& due_date);
int late_by_year(const date& returned_real_date, const date& due_date);
int late_by_month(const date& returned_real_date, const date& due_date);
int late_by_day(const date& returned_real_date, const date& due_date);

int main()
{
    auto returned_real_date{read_date()};
    auto due_date{read_date()};
    cout << (returned_real_date <= due_date ? 0 : calculate_fine(returned_real_date, due_date));
    return 0;
}

date read_date()
{
    int day, month, year;
    cin >> day >> month >> year;
    return {chrono::year{year}, chrono::month(month), chrono::day(day)};
}

int calculate_fine(const date& returned_real_date, const date& due_date)
{
    int fine = late_by_year(returned_real_date, due_date);
    if (fine)
        return fine;

    fine = late_by_month(returned_real_date, due_date);
    if (fine)
        return fine;

    return late_by_day(returned_real_date, due_date);
}

int late_by_year(const date& returned_real_date, const date& due_date)
{
    if (returned_real_date.year() > due_date.year()) {
        constexpr int per_year{10000};
        return per_year;
    }
    return 0;
}

int late_by_month(const date& returned_real_date, const date& due_date)
{
    if (returned_real_date.year() == due_date.year() && returned_real_date.month() > due_date.month()) {
        constexpr int per_month{500};
        return static_cast<int>((returned_real_date.month() - due_date.month()).count()) * per_month;
    }
    return 0;
}

int late_by_day(const date& returned_real_date, const date& due_date)
{
    if (returned_real_date.year() == due_date.year() && returned_real_date.month() == due_date.month() &&
        returned_real_date.day() > due_date.day()) {
        constexpr int per_day{15};
        return static_cast<int>((returned_real_date.day() - due_date.day()).count()) * per_day;
    }
    return 0;
}
