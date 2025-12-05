// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true
// C++23

import std;
using namespace std;

enum hackos_fine {
    hackos_days_fine = 15,
    hackos_months_fine = 500,
    hackos_years_fine = 10000
};

using date = struct {
    int day{}, month{}, year{};
};

date read_date();
int calculate_fine(const date& return_date, const date& due_date);
bool returned_on_time(const date& return_date, const date& due_date);

int main()
{
    date return_date{ read_date() };
    date due_date{ read_date() };
    cout << calculate_fine(return_date, due_date);
    return 0;
}

date read_date()
{
    date input_date;
    cin >> input_date.day >> input_date.month >> input_date.year;
    return input_date;
}

int calculate_fine(const date& return_date, const date& due_date)
{
    if (returned_on_time(return_date, due_date))
        return 0;
    if (return_date.year > due_date.year)
        return hackos_years_fine;
    if (return_date.month > due_date.month)
        return (return_date.month - due_date.month) * hackos_months_fine;
    return (return_date.day - due_date.day) * hackos_days_fine;
}

bool returned_on_time(const date& return_date, const date& due_date)
{
    return (return_date.year < due_date.year) ||
        ((return_date.year == due_date.year) && (return_date.month < due_date.month)) ||
        ((return_date.year == due_date.year) && (return_date.month == due_date.month) && (
            return_date.day <= due_date.day));
}
