// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true
// C23

#include <stdio.h>

typedef struct date_struct {
    int day, month, year;
} date;

void read_dates(date dates[]);
int calculate_fine(const date dates[]);
bool is_book_returned_until_due_date(const date *returned_real_date, const date *due_date);

int main()
{
    date dates[2];
    read_dates(dates);
    printf("%d\n", calculate_fine(dates));
    return 0;
}

void read_dates(date dates[])
{
    scanf("%d %d %d", &dates[0].day, &dates[0].month, &dates[0].year);
    scanf("%d %d %d", &dates[1].day, &dates[1].month, &dates[1].year);
}

int calculate_fine(const date dates[])
{
    auto returned_real_date = dates[0];
    auto due_date = dates[1];

    if (is_book_returned_until_due_date(&returned_real_date, &due_date))
        return 0;

    constexpr int per_year = 10000;
    if (returned_real_date.year > due_date.year)
        return per_year;

    constexpr int per_month = 500;
    if (returned_real_date.year == due_date.year && returned_real_date.month > due_date.month)
        return (returned_real_date.month - due_date.month) * per_month;

    // else is late by day
    constexpr int per_day = 15;
    return (returned_real_date.day - due_date.day) * per_day;
}

bool is_book_returned_until_due_date(const date *returned_real_date, const date *due_date)
{
    bool is_in_advance_by_year = returned_real_date->year < due_date->year;
    bool is_in_advance_by_month = returned_real_date->year == due_date->year
                                  && returned_real_date->month < due_date->month;
    bool is_until_due_date = returned_real_date->year == due_date->year
                             && returned_real_date->month == due_date->month
                             && returned_real_date->day <= due_date->day;
    return is_in_advance_by_year || is_in_advance_by_month || is_until_due_date;
}
