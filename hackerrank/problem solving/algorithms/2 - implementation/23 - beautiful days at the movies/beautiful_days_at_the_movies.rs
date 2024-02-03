// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

use text_io::read;

fn main() {
    let starting_day_number: i32 = read!();
    let ending_day_number: i32 = read!();
    let divisor: i32 = read!();
    println!(
        "{}",
        beautiful_days(starting_day_number, ending_day_number, divisor)
    );
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
    return (number - reverse_number).abs() % divisor == 0;
}
