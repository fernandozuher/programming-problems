// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut n_number_divisors: Vec<i32> = vec![0; n];

    for i in 0..n {
        let number: i32 = read!();
        n_number_divisors[i] = find_number_divisors_quantity(number)
    }

    print_array(&n_number_divisors);
}

fn find_number_divisors_quantity(number: i32) -> i32 {
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

fn print_array(array: &Vec<i32>) {
    array.iter().for_each(|x| println!("{}", x));
}
