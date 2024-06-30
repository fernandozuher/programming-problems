// https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

use text_io::read;

const TRANSITION_YEAR: i32 = 1918;

fn main() {
    let year: i32 = read!();
    print!("{}", find_date_of_256th_day(year));
}

    fn find_date_of_256th_day(year: i32) -> String {
        let mut date: String;

        if year != TRANSITION_YEAR {
            if is_leap_year(year) {
                date = "12.09.".to_string();
            } else {
                date = "13.09.".to_string();
            }
        } else {
            date = "26.09.".to_string();
        }

        date.push_str(&year.to_string());
        return date;
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
