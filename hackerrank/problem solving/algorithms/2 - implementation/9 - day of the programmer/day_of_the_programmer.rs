// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

use text_io::read;

const TRANSITION_YEAR: i32 = 1918;

fn main() {
    let year: i32 = read!();
    print!("{}", calculate_date_of_256th_day(year));
}

fn calculate_date_of_256th_day(year: i32) -> String {
    let day = if year == TRANSITION_YEAR {
        "26"
    } else if is_leap_year(year) {
        "12"
    } else {
        "13"
    };
    format!("{}.09.{}", day, year)
}

fn is_leap_year(year: i32) -> bool {
    if year < TRANSITION_YEAR {
        is_leap_julian_year(year)
    } else if year > TRANSITION_YEAR {
        is_leap_gregorian_year(year)
    }
    else {
        false
    }
}

fn is_leap_julian_year(year: i32) -> bool {
    year % 4 == 0
}

fn is_leap_gregorian_year(year: i32) -> bool {
    year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)
}
