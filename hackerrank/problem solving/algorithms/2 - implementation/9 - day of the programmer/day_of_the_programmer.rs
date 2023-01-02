// Source: https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen=true

use std::io::{self, BufRead};

fn main() {
    let year = read_line_as_vec_i32();

    let result = day_of_programmer(year[0]);
    println!("{}", result);
}

    fn read_line_as_vec_i32() -> Vec<i32> {
        let stdin = io::stdin();
        
        let numbers: Vec<i32> = stdin.lock()
          .lines().next().unwrap().unwrap()
          .trim().split(' ')
          .map(|s| s.parse().unwrap())
          .collect();

        return numbers;
    }

    fn day_of_programmer(year: i32) -> String  {
        let mut date: String;

        if year != 1918 {
            let is_leap: bool = if year > 1918 {is_leap_gregorian_year(year)} else {is_leap_julian_year(year)};
            date = if is_leap {"12.09.".to_string()} else {"13.09.".to_string()};
        }
        else {
            date = "26.09.".to_string();
        }

        date.push_str(&year.to_string());
        
        return date;
    }

        fn is_leap_gregorian_year(year: i32) -> bool {
            return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
        }

        fn is_leap_julian_year(year: i32) -> bool {
            return year % 4 == 0;
        }
