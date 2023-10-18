// https://www.hackerrank.com/challenges/30-nested-logic/problem?isFullScreen=true

#include <iostream>
using namespace std;

enum hackos_fine {
    hackos_days_fine = 15,
    hackos_months_fine = 500,
    hackos_years_fine = 10000
};

struct date {
    int day, month, year;
};

class Book_Return_Date {
public:
    Book_Return_Date(const date& returned_real_date, const date& due_date):
        returned_real_date{returned_real_date}, due_date{due_date}
    {
        calculate_fine();
    }

    int fine() const
    {
        return fine_amount;
    }

private:
    date returned_real_date, due_date;
    int fine_amount;

    void calculate_fine()
    {
        if (returned_real_date.year < due_date.year)
            fine_amount = 0;
        else if (returned_real_date.year == due_date.year) {
            if (returned_real_date.month < due_date.month)
                fine_amount = 0;
            else if (returned_real_date.month == due_date.month)
                fine_amount = (returned_real_date.day < due_date.day) ? 0 : (returned_real_date.day - due_date.day) * hackos_days_fine;
            else
                fine_amount = (returned_real_date.month - due_date.month) * hackos_months_fine;
        }
        else
            fine_amount = hackos_years_fine;
    }
};

void read_stdin_dates(date& returned_real_date, date& due_date);

int main()
{
    date returned_real_date, due_date;
    read_stdin_dates(returned_real_date, due_date);

    Book_Return_Date book_return_date_obj(returned_real_date, due_date);
    cout << book_return_date_obj.fine();

    return 0;
}

void read_stdin_dates(date& returned_real_date, date& due_date)
{
    cin >> returned_real_date.day >> returned_real_date.month >> returned_real_date.year
        >> due_date.day >> due_date.month >> due_date.year;
}
