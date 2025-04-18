// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

#include <iostream>
#include <tuple>

using namespace std;

enum class Hackos_Fine {
    per_day = 15,
    per_month = 500,
    per_year = 10000
};

using date = struct date {
    int day{}, month{}, year{};

    bool operator<=(const date& other) const
    {
        return tie(year, month, day) <= tie(other.year, other.month, other.day);
    }
};

tuple<date, date> read_dates();
int calculate_fine(const date& returned_real_date, const date& due_date);

int main()
{
    auto [returned_real_date, due_date] = read_dates();
    cout << (returned_real_date <= due_date ? 0 : calculate_fine(returned_real_date, due_date));
    return 0;
}

tuple<date, date> read_dates()
{
    date returned_real_date, due_date;
    cin >> returned_real_date.day >> returned_real_date.month >> returned_real_date.year;
    cin >> due_date.day >> due_date.month >> due_date.year;
    return {returned_real_date, due_date};
}

int calculate_fine(const date& returned_real_date, const date& due_date)
{
    if (returned_real_date.year > due_date.year)
        return static_cast<int>(Hackos_Fine::per_year);
    if (returned_real_date.year == due_date.year && returned_real_date.month > due_date.month)
        return (returned_real_date.month - due_date.month) * static_cast<int>(Hackos_Fine::per_month);
    return (returned_real_date.day - due_date.day) * static_cast<int>(Hackos_Fine::per_day);
}
