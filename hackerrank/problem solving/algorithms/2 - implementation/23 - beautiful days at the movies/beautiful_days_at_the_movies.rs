// Source: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

use std::io::{self, BufRead};


fn main() {
    let input_line: Vec<i32> = read_line_as_vec_i32();
    let starting_day_number: i32 = *input_line.first().unwrap();
    let ending_day_number: i32 = input_line[1];
    let divisor: i32 = *input_line.last().unwrap();

    let n_beautiful_days: i32 = beautiful_days(starting_day_number, ending_day_number, divisor);

    println!("{}", n_beautiful_days);
}

    fn read_line_as_vec_i32() -> Vec<i32> {
        let stdin = io::stdin();

        let input_line: Vec<i32> = stdin.lock()
        .lines().next().unwrap().unwrap()
        .trim().split(' ')
        .map(|data| data.parse().unwrap())
        .collect();

        return input_line;
    }

    fn beautiful_days(starting_day_number: i32, ending_day_number: i32, divisor: i32) -> i32 {
        let mut n_beautiful_days = 0;

        for number in starting_day_number..=ending_day_number {
            let reverse_number: i32 = generate_reverse_number(number);

            if is_day_beautiful(number, reverse_number, divisor) {
                n_beautiful_days += 1;
            }
        }

        return n_beautiful_days;
    }

        fn generate_reverse_number(mut number: i32) -> i32 {
            let mut reverse_number = 0;

            while number > 0 {
                reverse_number = (reverse_number * 10) + (number % 10);
                number /= 10;
            }

            return reverse_number;
        }

        fn is_day_beautiful(number: i32, reverse_number: i32, divisor: i32) -> bool {
            let beautiful_day: bool = (number - reverse_number).abs() % divisor == 0;
            return beautiful_day;
        }
