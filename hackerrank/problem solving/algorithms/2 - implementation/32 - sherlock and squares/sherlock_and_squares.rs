// Source: https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

fn main() {
    let n_test_cases: usize = read!();
    let mut output: Vec<i32> = Vec::with_capacity(n_test_cases);
    unsafe {
        output.set_len(n_test_cases);
    }

    for element in output.iter_mut() {
        let begin: i32 = read!();
        let end: i32 = read!();
        *element = calculate_number_of_square_integers_in_range(begin, end);
    }

    print_array(output);
}

fn calculate_number_of_square_integers_in_range(begin: i32, end: i32) -> i32 {
    let mut number: i32 = find_first_square_integer_from_number(begin);
    let mut squares: i32 = 0;
    while is_power_of_2_of_number_less_than_or_equal_to_limit(number, end) {
        number += 1;
        squares += 1;
    }
    return squares;
}

fn find_first_square_integer_from_number(number: i32) -> i32 {
    let square_root_number: f64 = (number as f64).sqrt();
    let square_integer: i32 = get_square_integer_from_number(square_root_number);
    return square_integer;
}

fn get_square_integer_from_number(number: f64) -> i32 {
    let mut integer_part: f64 = number.trunc();
    if number != integer_part {
        integer_part += 1 as f64;
    }
    return integer_part as i32;
}

fn is_power_of_2_of_number_less_than_or_equal_to_limit(number: i32, limit: i32) -> bool {
    return i32::pow(number, 2) <= limit;
}

fn print_array(array: Vec<i32>) {
    array.iter().for_each(|element| println!("{}", element));
}
