// Source: https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

fn main() {
    let lower_limit = read!();
    let upper_limit = read!();

    let output: Vec<u64> = find_kaprekar_numbers_in_range(lower_limit, upper_limit);
    print_output(&output);
}

fn find_kaprekar_numbers_in_range(lower_limit: u64, upper_limit: u64) -> Vec<u64> {
    let mut kaprekar_numbers: Vec<u64> = Vec::new();

    for number in lower_limit..=upper_limit {
        let potential_kaprekar_number: u64 = calculate_potential_kaprekar_number(number);
        if number == potential_kaprekar_number {
            kaprekar_numbers.push(number)
        }
    }

    return kaprekar_numbers;
}

fn calculate_potential_kaprekar_number(number: u64) -> u64 {
    let mut string_number: String = number.to_string();
    let quantity_of_digits: usize = string_number.len();

    let square_number = number.pow(2);
    string_number = square_number.to_string();

    let left_digits = string_number.len() - quantity_of_digits;
    let left_string_number: String = string_number.chars().skip(0).take(left_digits).collect();

    let right_digits = string_number.len() - left_digits;
    let right_string_number: String = string_number
        .chars()
        .skip(left_digits)
        .take(right_digits)
        .collect();

    let potential_kaprekar_number: u64 =
        sum_string_numbers(left_string_number, right_string_number);

    return potential_kaprekar_number;
}

fn sum_string_numbers(left_string_number: String, right_string_number: String) -> u64 {
    if left_string_number.len() > 0 && right_string_number.len() > 0 {
        return left_string_number.parse::<u64>().unwrap()
            + right_string_number.parse::<u64>().unwrap();
    } else if left_string_number.len() == 0 {
        return right_string_number.parse::<u64>().unwrap();
    } else if right_string_number.len() == 0 {
        return left_string_number.parse::<u64>().unwrap();
    }
    return 0;
}

fn print_output(array: &Vec<u64>) {
    if !array.is_empty() {
        array.iter().for_each(|element| print!("{} ", element));
    } else {
        println!("INVALID RANGE");
    }
}
