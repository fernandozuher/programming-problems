// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

use chrono::{Datelike, NaiveDate};
use text_io::read;

enum HackosFine {
    HackosDaysFine = 15,
    HackosMonthsFine = 500,
    HackosYearsFine = 10000,
}

fn main() {
    let return_date: NaiveDate = read_date();
    let due_date: NaiveDate = read_date();
    println!("{}", calculate_fine(&return_date, &due_date));
}

fn read_date() -> NaiveDate {
    let day: u32 = read!();
    let month: u32 = read!();
    let year: i32 = read!();
    NaiveDate::from_ymd_opt(year, month, day).unwrap()
}

fn calculate_fine(return_date: &NaiveDate, due_date: &NaiveDate) -> u32 {
    if returned_on_time(return_date, due_date) {
        0
    } else if return_date.year() > due_date.year() {
        HackosFine::HackosYearsFine as u32
    } else if return_date.month() > due_date.month() {
        (return_date.month() - due_date.month()) * HackosFine::HackosMonthsFine as u32
    } else {
        (return_date.day() - due_date.day()) * HackosFine::HackosDaysFine as u32
    }
}

fn returned_on_time(return_date: &NaiveDate, due_date: &NaiveDate) -> bool {
    (return_date.year() < due_date.year())
        || ((return_date.year() == due_date.year()) && (return_date.month() < due_date.month()))
        || ((return_date.year() == due_date.year())
            && (return_date.month() == due_date.month())
            && (return_date.day() <= due_date.day()))
}
