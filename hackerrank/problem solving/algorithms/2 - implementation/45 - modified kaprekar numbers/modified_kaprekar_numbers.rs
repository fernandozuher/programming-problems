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
    let square_number_in_string: String = number.pow(2).to_string();
    let size_of_string: usize = number.to_string().len();

    let left_number_in_string: String =
        get_left_number_in_string(&square_number_in_string, size_of_string);

    let right_number_in_string: String =
        get_right_number_in_string(&square_number_in_string, size_of_string);

    let potential_kaprekar_number: u64 =
        sum_numbers_in_strings(left_number_in_string, right_number_in_string);

    return potential_kaprekar_number;
}

fn get_left_number_in_string(square_number_in_string: &String, size_of_string: usize) -> String {
    let digits_to_skip: usize = 0;
    let digits_to_take: usize = square_number_in_string.len() - size_of_string;
    let number_in_string: String = square_number_in_string
        .chars()
        .skip(digits_to_skip)
        .take(digits_to_take)
        .collect();
    return number_in_string;
}

fn get_right_number_in_string(square_number_in_string: &String, size_of_string: usize) -> String {
    let digits_to_skip: usize = square_number_in_string.len() - size_of_string;
    let digits_to_take: usize = square_number_in_string.len() - digits_to_skip;
    let number_in_string: String = square_number_in_string
        .chars()
        .skip(digits_to_skip)
        .take(digits_to_take)
        .collect();
    return number_in_string;
}

fn sum_numbers_in_strings(left_number_in_string: String, right_number_in_string: String) -> u64 {
    if left_number_in_string.len() > 0 && right_number_in_string.len() > 0 {
        return left_number_in_string.parse::<u64>().unwrap()
            + right_number_in_string.parse::<u64>().unwrap();
    } else if left_number_in_string.len() == 0 {
        return right_number_in_string.parse::<u64>().unwrap();
    } else if right_number_in_string.len() == 0 {
        return left_number_in_string.parse::<u64>().unwrap();
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
