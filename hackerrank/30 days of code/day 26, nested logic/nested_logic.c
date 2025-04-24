// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true
// C23

#include <stdio.h>

typedef struct date_struct {
    int day, month, year;
} date;

date read_date();

bool is_book_returned_until_due_date(const date *returned_date, const date *due_date);
bool is_in_advance_by_year(const date *returned_date, const date *due_date);
bool is_in_advance_by_month(const date *returned_date, const date *due_date);
bool is_until_due_date(const date *returned_date, const date *due_date);

int calculate_fine(const date *returned_date, const date *due_date);
int late_by_year(const date *returned_date, const date *due_date);
int late_by_month(const date *returned_date, const date *due_date);
int late_by_day(const date *returned_date, const date *due_date);

int main()
{
    date returned_date = read_date();
    date due_date = read_date();
    int fine = is_book_returned_until_due_date(&returned_date, &due_date)
                   ? 0
                   : calculate_fine(&returned_date, &due_date);
    printf("%d\n", fine);

    return 0;
}

date read_date()
{
    date x;
    scanf("%d %d %d", &x.day, &x.month, &x.year);
    return x;
}

bool is_book_returned_until_due_date(const date *returned_date, const date *due_date)
{
    return is_in_advance_by_year(returned_date, due_date)
           || is_in_advance_by_month(returned_date, due_date)
           || is_until_due_date(returned_date, due_date);
}

bool is_in_advance_by_year(const date *returned_date, const date *due_date)
{
    return returned_date->year < due_date->year;
}

bool is_in_advance_by_month(const date *returned_date, const date *due_date)
{
    return returned_date->year == due_date->year && returned_date->month < due_date->month;
}

bool is_until_due_date(const date *returned_date, const date *due_date)
{
    return returned_date->year == due_date->year && returned_date->month == due_date->month
           && returned_date->day <= due_date->day;
}

int calculate_fine(const date *returned_date, const date *due_date)
{
    int fine = late_by_year(returned_date, due_date);
    if (fine)
        return fine;

    fine = late_by_month(returned_date, due_date);
    if (fine)
        return fine;

    return late_by_day(returned_date, due_date);
}

int late_by_year(const date *returned_date, const date *due_date)
{
    if (returned_date->year > due_date->year) {
        constexpr int per_year = 10000;
        return per_year;
    }
    return 0;
}

int late_by_month(const date *returned_date, const date *due_date)
{
    if (returned_date->year == due_date->year && returned_date->month > due_date->month) {
        constexpr int per_month = 500;
        return (returned_date->month - due_date->month) * per_month;
    }
    return 0;
}

int late_by_day(const date *returned_date, const date *due_date)
{
    if (returned_date->year == due_date->year && returned_date->month == due_date->month
        && returned_date->day > due_date->day) {
        constexpr int per_day = 15;
        return (returned_date->day - due_date->day) * per_day;
    }
    return 0;
}
