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

class Library_Fine {
private:
    date _return_date;
    date _due_date;
    int _fine;

    void _calculate_fine() {
        if (_were_books_returned_in_time())
            _fine = {0};
        else if (_is_return_date_late_in_more_than_or_equal_to_one_year())
            _fine = {hackos_years_fine};
        else if (_is_return_date_late_in_more_than_or_equal_to_one_month())
            _fine = {(_return_date.month - _due_date.month) * hackos_months_fine};
        else
            _fine = {(_return_date.day - _due_date.day) * hackos_days_fine};
    }

        bool _were_books_returned_in_time() const {
            if ((_return_date.year < _due_date.year) ||
                    ((_return_date.year == _due_date.year) && (_return_date.month < _due_date.month)) ||
                    ((_return_date.year == _due_date.year) && (_return_date.month == _due_date.month) && (_return_date.day <= _due_date.day))
               )
                return true;
            return false;
        }

        bool _is_return_date_late_in_more_than_or_equal_to_one_year() const {
            return _return_date.year > _due_date.year;
        }

        bool _is_return_date_late_in_more_than_or_equal_to_one_month() const {
            return _return_date.month > _due_date.month;
        }

public:
    Library_Fine(const date RETURN_DATE, const date DUE_DATE) {
        _return_date = {RETURN_DATE};
        _due_date = {DUE_DATE};
        _fine = {0};

        _calculate_fine();
    }

    int getFine() const {
        return _fine;
    }
};

int main() {
    const date RETURN_DATE {read_a_date()};
    const date DUE_DATE {read_a_date()};

    const Library_Fine OBJ(RETURN_DATE, DUE_DATE);
    const int FINE {OBJ.getFine()};
    cout << FINE << "\n";

    return 0;
}

    date read_a_date() {
        date input_date;
        cin >> input_date.day >> input_date.month >> input_date.year;
        return input_date;
    }
