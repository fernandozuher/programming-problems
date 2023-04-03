// Source: https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

fn main() {
    let n_test_cases: usize = read!();
    let mut output: Vec<i32> = Vec::with_capacity(n_test_cases);
    unsafe {
        output.set_len(n_test_cases);
    }

    output.fill_with(find_numbers_divisors_quantity);
    print_output(output);
}

fn find_numbers_divisors_quantity() -> i32 {
    let number: i32 = read!();
    let mut current_number = number;
    let mut divisors: i32 = 0;

    while current_number != 0 {
        let divisor: i32 = get_last_digit_of_number(current_number);
        if is_number_evenly_divided_by_divisor(number, divisor) {
            divisors += 1
        }
        current_number = remove_last_digit_of_number(current_number);
    }

    return divisors;
}

fn get_last_digit_of_number(number: i32) -> i32 {
    return number % 10;
}

fn is_number_evenly_divided_by_divisor(number: i32, divisor: i32) -> bool {
    return divisor != 0 && number % divisor == 0;
}

fn remove_last_digit_of_number(number: i32) -> i32 {
    return number / 10;
}

fn print_output(array: Vec<i32>) {
    array.iter().for_each(|element| println!("{}", element));
}
