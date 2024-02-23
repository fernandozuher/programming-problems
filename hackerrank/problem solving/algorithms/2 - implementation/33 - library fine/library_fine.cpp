// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

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

class Library_Fine {
public:
    Library_Fine(const date& return_date, const date& due_date);
    int fine() const;

private:
    date return_date;
    date due_date;
    int fine_amount;

    void calculate_fine();
    bool were_books_returned_in_time() const;
    bool is_return_date_late_in_more_than_or_equal_to_one_year() const;
    bool is_return_date_late_in_more_than_or_equal_to_one_month() const;
};

    Library_Fine::Library_Fine(const date& return_date, const date& due_date)
        : return_date{return_date}, due_date{due_date}, fine_amount{}
    {
        calculate_fine();
    }

        void Library_Fine::calculate_fine()
        {
            if (were_books_returned_in_time())
                fine_amount = 0;
            else if (is_return_date_late_in_more_than_or_equal_to_one_year())
                fine_amount = hackos_years_fine;
            else if (is_return_date_late_in_more_than_or_equal_to_one_month())
                fine_amount = (return_date.month - due_date.month) * hackos_months_fine;
            else
                fine_amount = (return_date.day - due_date.day) * hackos_days_fine;
        }

            bool Library_Fine::were_books_returned_in_time() const
            {
                if ((return_date.year < due_date.year) ||
                        ((return_date.year == due_date.year) && (return_date.month < due_date.month)) ||
                        ((return_date.year == due_date.year) && (return_date.month == due_date.month) && (return_date.day <= due_date.day))
                   )
                    return true;
                return false;
            }

            bool Library_Fine::is_return_date_late_in_more_than_or_equal_to_one_year() const
            {
                return return_date.year > due_date.year;
            }

            bool Library_Fine::is_return_date_late_in_more_than_or_equal_to_one_month() const
            {
                return return_date.month > due_date.month;
            }

    int Library_Fine::fine() const
    {
        return fine_amount;
    }

//////////////////////////////////////////////////

date read_a_date();

int main()
{
    date return_date {read_a_date()};
    date due_date {read_a_date()};

    Library_Fine obj(return_date, due_date);
    int fine {obj.fine()};
    cout << fine << "\n";

    return 0;
}

    date read_a_date()
    {
        date input_date;
        cin >> input_date.day >> input_date.month >> input_date.year;
        return input_date;
    }
