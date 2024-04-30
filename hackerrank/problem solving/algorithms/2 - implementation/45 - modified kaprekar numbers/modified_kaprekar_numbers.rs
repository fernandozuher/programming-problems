// https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

use text_io::read;

fn main() {
    let lower_limit: u64 = read!();
    let upper_limit: u64 = read!();
    let mut valid_range: bool = false;

    (lower_limit..=upper_limit).for_each(|x| {
        if is_number_kaprekar(x) {
            print!("{} ", x);
            valid_range = true;
        }
    });

    if !valid_range {
        println!("INVALID RANGE");
    }
}

fn is_number_kaprekar(number: u64) -> bool {
    let square_number: u64 = number.pow(2);
    let divisor: u64 = u64::pow(10u64, number_digits(number));
    let (left_number, right_number) = (square_number / divisor, square_number % divisor);
    return number == left_number + right_number;
}

fn number_digits(n: u64) -> u32 {
    if n < 10 {
        1
    } else if n < 100 {
        2
    } else if n < 1000 {
        3
    } else if n < 10000 {
        4
    } else if n < 100000 {
        5
    } else if n < 1000000 {
        6
    } else if n < 10000000 {
        7
    } else {
        8
    }
}
