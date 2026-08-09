// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?is_full_screen=true

use morfo::read;

fn main() {
    let start_day: i32 = read();
    let end_day: i32 = read();
    let divisor: i32 = read();
    println!("{}", beautiful_days(start_day, end_day, divisor));
}

// n: range (end_day - start_day + 1)
// d: number of digits of the largest day
// T: O(n * d)
// S: O(d) extra space
fn beautiful_days(start_day: i32, end_day: i32, divisor: i32) -> usize {
    (start_day..=end_day)
        .filter(|&day| is_beautiful_day(day, divisor))
        .count()
}

fn is_beautiful_day(day: i32, divisor: i32) -> bool {
    (day - reverse_number(day)) % divisor == 0
}

fn reverse_number(number: i32) -> i32 {
    number
        .to_string()
        .chars()
        .rev()
        .collect::<String>()
        .parse()
        .unwrap()
}
