// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

use text_io::read;

const TRANSITION_YEAR: i32 = 1918;

fn main() {
    let year: i32 = read!();
    println!("{}", find_date_of_256th_day(year));
}

fn find_date_of_256th_day(year: i32) -> String {
    let mut date: String = find_day_month_of_256th_day(year);
    date = add_year_to_date(year, date);
    return date;
}

fn find_day_month_of_256th_day(year: i32) -> String {
    if year != TRANSITION_YEAR {
        if is_leap_year(year) {
            return "12.09.".to_string();
        } else {
            return "13.09.".to_string();
        }
    } else {
        return "26.09.".to_string();
    }
}

fn is_leap_year(year: i32) -> bool {
    if year > TRANSITION_YEAR {
        is_leap_gregorian_year(year)
    } else {
        is_leap_julian_year(year)
    }
}

fn is_leap_gregorian_year(year: i32) -> bool {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

fn is_leap_julian_year(year: i32) -> bool {
    return year % 4 == 0;
}

fn add_year_to_date(year: i32, mut date: String) -> String {
    date.push_str(&year.to_string());
    return date;
}
