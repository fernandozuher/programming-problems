// https://www.hackerrank.com/challenges/30-nested-logic/problem?is_full_screen=true

use text_io::read;
use chrono::{DateLike};

fn main() {
    let (returned_real_date: NaiveDate, due_date: NaiveDate) = read_stdin_dates();
    let book_return_date = Book_Return_Date(returned_real_date, due_date);
    println!("{}", book_return_date.fine());
}

fn read_stdin_dates() -> (NaiveDate, NaiveDate) {
    let date1, date2: String, String = read!(), read!();
    let returned_real_date = NaiveDate::parse_from_str(date1, "d% m% Y%").unwrap();
    let returned_real_date = NaiveDate::parse_from_str(date2, "d% m% Y%").unwrap();
    return (returned_real_date, due_date);
}

struct Book_Return_Date {
    returned_real_date: String,
    due_date: String,
    fine_amount: i32,
}

impl Book_Return_Date {
    fn default(returned_real_date, due_date) -> Self {
        Book_Return_Date {
            returned_real_date: returned_real_date,
            due_date: due_date,
            fine_amount: 0,
        }
    }

    fn fine(&self) -> i32 {
        return self.fine;
    }


    fn calculate_fine(&self) {
        if self.returned_real_date <= self.due_date {
            self.fine = 0;
        }
        else if self.returned_real_date.year == self.due_date.year {
            if self.returned_real_date.mon == self.due_date.mon {
                self.fine = (self.returned_real_date.mday - self.due_date.mday) * Hackos_Fine::Hackos_days_fine;
            }
            else {
                self.fine = (self.returned_real_date.mon - self.due_date.mon) * Hackos_Fine::Hackos_months_fine;
            }
        }
        else {
            self.fine = Hackos_Fine::Hackos_years_fine;
        }
        
        return self.fine;
    }    
}

enum Hackos_Fine {
    Hackos_days_fine = 15,
    Hackos_months_fine = 500,
    Hackos_years_fine = 10000
}
