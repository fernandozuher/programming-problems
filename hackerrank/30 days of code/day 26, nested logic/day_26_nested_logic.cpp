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

class Book_Return_Date {
private:
	date returned_real_date, due_date;
	int fine;

	void calculate_fine() {
		if (returned_real_date.year < due_date.year)
			fine = 0;
		else if (returned_real_date.year == due_date.year) {
			if (returned_real_date.month < due_date.month)
				fine = 0;
			else if (returned_real_date.month == due_date.month)
				fine = (returned_real_date.day < due_date.day) ? 0 : (returned_real_date.day - due_date.day) * hackos_days_fine;
			else
				fine = (returned_real_date.month - due_date.month) * hackos_months_fine;
		}
		else
			fine = hackos_years_fine;
	}

public:
	Book_Return_Date(date returned_real_date, date due_date):
		returned_real_date(returned_real_date), due_date(due_date) {
		calculate_fine();
	}

	int get_fine() const {
		return fine;
	}
};

void read_stdin_dates(date &returned_real_date, date &due_date) {
	cin >> returned_real_date.day >> returned_real_date.month >> returned_real_date.year
	    >> due_date.day >> due_date.month >> due_date.year;
}

int main() {
	date returned_real_date, due_date;
	read_stdin_dates(returned_real_date, due_date);

	Book_Return_Date book_return_date_obj(returned_real_date, due_date);
	cout << book_return_date_obj.get_fine();

	return 0;
}
