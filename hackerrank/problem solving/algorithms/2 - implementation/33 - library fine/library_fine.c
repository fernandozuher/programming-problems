// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

#include <stdbool.h>
#include <stdio.h>

enum hackos_fine {
    hackos_days_fine = 15,
    hackos_months_fine = 500,
    hackos_years_fine = 10000
};

typedef struct {
    int day, month, year;
} date;

date read_a_date();
int calculate_fine(const date return_date, const date due_date);
    bool were_books_returned_in_time(const date return_date, const date due_date);
    bool is_return_date_late_in_more_than_or_equal_to_one_year(const int return_date_year, const int due_date_year);
    bool is_return_date_late_in_more_than_or_equal_to_one_month(const int return_date_month, const int due_date_month);

int main()
{
    date return_date = read_a_date();
    date due_date = read_a_date();
    printf("%d\n", calculate_fine(return_date, due_date));

    return 0;
}

    date read_a_date()
    {
        date input_date;
        scanf("%d %d %d", &input_date.day, &input_date.month, &input_date.year);
        return input_date;
    }

    int calculate_fine(const date return_date, const date due_date)
    {
        int fine;

        if (were_books_returned_in_time(return_date, due_date))
            fine = 0;
        else if (is_return_date_late_in_more_than_or_equal_to_one_year(return_date.year, due_date.year))
            fine = hackos_years_fine;
        else if (is_return_date_late_in_more_than_or_equal_to_one_month(return_date.month, due_date.month))
            fine = (return_date.month - due_date.month) * hackos_months_fine;
        else
            fine = (return_date.day - due_date.day) * hackos_days_fine;

        return fine;
    }

        bool were_books_returned_in_time(const date return_date, const date due_date)
        {
            if ((return_date.year < due_date.year) ||
                    ((return_date.year == due_date.year) && (return_date.month < due_date.month)) ||
                    ((return_date.year == due_date.year) && (return_date.month == due_date.month) && (return_date.day <= due_date.day))
               )
                return true;
            return false;
        }

        bool is_return_date_late_in_more_than_or_equal_to_one_year(const int return_date_year, const int due_date_year)
        {
            return return_date_year > due_date_year;
        }

        bool is_return_date_late_in_more_than_or_equal_to_one_month(const int return_date_month, const int due_date_month)
        {
            return return_date_month > due_date_month;
        }
