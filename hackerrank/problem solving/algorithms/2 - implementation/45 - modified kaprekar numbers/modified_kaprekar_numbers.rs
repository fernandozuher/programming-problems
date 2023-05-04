// Source: https://www.hackerrank.com/challenges/kaprekar-numbers/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

fn main() {
    let lower_limit: i32 = read!();
    let upper_limit: i32 = read!();

    let output: Vec<i32> = find_kaprekar_numbers_in_range(lower_limit, upper_limit);
    print_output(&output);
}

fn find_kaprekar_numbers_in_range(lower_limit: i32, upper_limit: i32) -> Vec<i32> {
    let mut kaprekar_numbers: Vec<i32> = Vec::new();

    for number in lower_limit..=upper_limit {
        let potential_kaprekar_number: i32 = calculate_potential_kaprekar_number(number);
        if number == potential_kaprekar_number {
            kaprekar_numbers.push(number)
        }
    }

    return kaprekar_numbers;
}

fn calculate_potential_kaprekar_number(number: i32) -> i32 {
    let square_number_in_string: String = (number as u64).pow(2).to_string();
    let length_of_number_in_string: usize = number.to_string().len();

    let left_number_in_string: String =
        get_left_number_in_string(&square_number_in_string, length_of_number_in_string);

    let right_number_in_string: String =
        get_right_number_in_string(&square_number_in_string, length_of_number_in_string);

    let potential_kaprekar_number: i32 =
        sum_numbers_in_strings(left_number_in_string, right_number_in_string);

    return potential_kaprekar_number;
}

fn get_left_number_in_string(
    square_number_in_string: &String,
    length_of_number_in_string: usize,
) -> String {
    let digits_to_skip: usize = 0;
    let digits_to_take: usize = square_number_in_string.len() - length_of_number_in_string;
    let number_in_string: String = square_number_in_string
        .chars()
        .skip(digits_to_skip)
        .take(digits_to_take)
        .collect();
    return number_in_string;
}

fn get_right_number_in_string(
    square_number_in_string: &String,
    length_of_number_in_string: usize,
) -> String {
    let digits_to_skip: usize = square_number_in_string.len() - length_of_number_in_string;
    let digits_to_take: usize = square_number_in_string.len() - digits_to_skip;
    let number_in_string: String = square_number_in_string
        .chars()
        .skip(digits_to_skip)
        .take(digits_to_take)
        .collect();
    return number_in_string;
}

fn sum_numbers_in_strings(left_number_in_string: String, right_number_in_string: String) -> i32 {
    if left_number_in_string.len() > 0 && right_number_in_string.len() > 0 {
        return left_number_in_string.parse::<i32>().unwrap()
            + right_number_in_string.parse::<i32>().unwrap();
    } else if left_number_in_string.len() == 0 {
        return right_number_in_string.parse::<i32>().unwrap();
    } else if right_number_in_string.len() == 0 {
        return left_number_in_string.parse::<i32>().unwrap();
    }
    return 0;
}

fn print_output(array: &Vec<i32>) {
    if !array.is_empty() {
        array.iter().for_each(|element| print!("{} ", element));
    } else {
        println!("INVALID RANGE");
    }
}
