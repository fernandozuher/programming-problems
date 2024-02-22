// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut output: Vec<i32> = vec![0; n];

    for element in output.iter_mut() {
        let begin: i32 = read!();
        let end: i32 = read!();
        *element = calculate_quantity_of_square_integers_in_range(begin, end);
    }

    print_array(&output);
}

fn calculate_quantity_of_square_integers_in_range(begin: i32, end: i32) -> i32 {
    let mut number: i32 = find_first_square_integer(begin);
    let mut squares: i32 = 0;
    while is_power_of_2_less_than_or_equal_to_limit(number, end) {
        number += 1;
        squares += 1;
    }
    return squares;
}

fn find_first_square_integer(x: i32) -> i32 {
    let square_root: f64 = (x as f64).sqrt();
    let mut integer_part: f64 = square_root.trunc();
    if square_root != integer_part {
        integer_part += 1 as f64;
    }
    return integer_part as i32;
}

fn is_power_of_2_less_than_or_equal_to_limit(x: i32, limit: i32) -> bool {
    return i32::pow(x, 2) <= limit;
}

fn print_array(array: &Vec<i32>) {
    array.iter().for_each(|x| println!("{}", x));
}
