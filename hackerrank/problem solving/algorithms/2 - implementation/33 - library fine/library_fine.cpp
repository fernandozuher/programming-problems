// Source: https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

#include <iostream>

using namespace std;

enum hackos_fine {
    hackos_days_fine = 15,
    hackos_months_fine = 500,
    hackos_years_fine = 10000
};

typedef struct date_struct {
    int day, month, year;
} date;

date read_a_date();
int calculate_fine(const date RETURN_DATE, const date DUE_DATE);
    bool were_books_returned_in_time(const date RETURN_DATE, const date DUE_DATE);
    bool is_return_date_late_in_more_than_or_equal_to_one_year(const int RETURN_DATE_YEAR, const int DUE_DATE_YEAR);
    bool is_return_date_late_in_more_than_or_equal_to_one_month(const int RETURN_DATE_MONTH, const int DUE_DATE_MONTH);


int main() {
    const date RETURN_DATE {read_a_date()};
    const date DUE_DATE {read_a_date()};

    const int FINE {calculate_fine(RETURN_DATE, DUE_DATE)};
    cout << FINE << "\n";

    return 0;
}

    date read_a_date() {
        date input_date;
        cin >> input_date.day >> input_date.month >> input_date.year;
        return input_date;
    }

    int calculate_fine(const date RETURN_DATE, const date DUE_DATE) {
        int fine;

        if (were_books_returned_in_time(RETURN_DATE, DUE_DATE))
            fine = {0};
        else if (is_return_date_late_in_more_than_or_equal_to_one_year(RETURN_DATE.year, DUE_DATE.year))
            fine = {hackos_years_fine};
        else if (is_return_date_late_in_more_than_or_equal_to_one_month(RETURN_DATE.month, DUE_DATE.month))
            fine = {(RETURN_DATE.month - DUE_DATE.month) * hackos_months_fine};
        else
            fine = {(RETURN_DATE.day - DUE_DATE.day) * hackos_days_fine};

        return fine;
    }

        bool were_books_returned_in_time(const date RETURN_DATE, const date DUE_DATE) {
            if ((RETURN_DATE.year < DUE_DATE.year) ||
                    ((RETURN_DATE.year == DUE_DATE.year) && (RETURN_DATE.month < DUE_DATE.month)) ||
                    ((RETURN_DATE.year == DUE_DATE.year) && (RETURN_DATE.month == DUE_DATE.month) && (RETURN_DATE.day <= DUE_DATE.day))
               )
                return true;
            return false;
        }

        bool is_return_date_late_in_more_than_or_equal_to_one_year(const int RETURN_DATE_YEAR, const int DUE_DATE_YEAR) {
            return RETURN_DATE_YEAR > DUE_DATE_YEAR;
        }

        bool is_return_date_late_in_more_than_or_equal_to_one_month(const int RETURN_DATE_MONTH, const int DUE_DATE_MONTH) {
            return RETURN_DATE_MONTH > DUE_DATE_MONTH;
        }
