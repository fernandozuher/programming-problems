// Source: https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

use chrono::Datelike;
use chrono::NaiveDate;
use text_io::read;

enum HackosFine {
    HackosDaysFine = 15,
    HackosMonthsFine = 500,
    HackosYearsFine = 10000,
}

fn main() {
    let return_date: NaiveDate = read_a_date();
    let due_date: NaiveDate = read_a_date();

    let fine: u32 = calculate_fine(return_date, due_date);
    println!("{}", fine);
}

fn read_a_date() -> NaiveDate {
    let day: u32 = read!();
    let month: u32 = read!();
    let year: i32 = read!();

    let from_ymd_opt = NaiveDate::from_ymd_opt;
    let date: NaiveDate = from_ymd_opt(year, month, day).unwrap();
    return date;
}

fn calculate_fine(return_date: NaiveDate, due_date: NaiveDate) -> u32 {
    let fine: u32;

    if were_books_returned_in_time(return_date, due_date) {
        fine = 0;
    } else if is_return_date_late_in_more_than_or_equal_to_one_year(
        return_date.year(),
        due_date.year(),
    ) {
        fine = HackosFine::HackosYearsFine as u32;
    } else if is_return_date_late_in_more_than_or_equal_to_one_month(
        return_date.month(),
        due_date.month(),
    ) {
        fine = (return_date.month() - due_date.month()) * HackosFine::HackosMonthsFine as u32;
    } else {
        fine = (return_date.day() - due_date.day()) * HackosFine::HackosDaysFine as u32;
    }

    return fine;
}

fn were_books_returned_in_time(return_date: NaiveDate, due_date: NaiveDate) -> bool {
    if (return_date.year() < due_date.year())
        || ((return_date.year() == due_date.year()) && (return_date.month() < due_date.month()))
        || ((return_date.year() == due_date.year())
            && (return_date.month() == due_date.month())
            && (return_date.day() <= due_date.day()))
    {
        return true;
    }
    return false;
}

fn is_return_date_late_in_more_than_or_equal_to_one_year(
    return_date_year: i32,
    due_date_year: i32,
) -> bool {
    return return_date_year > due_date_year;
}

fn is_return_date_late_in_more_than_or_equal_to_one_month(
    return_date_month: u32,
    due_date_month: u32,
) -> bool {
    return return_date_month > due_date_month;
}
