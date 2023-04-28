// Source: https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

use std::convert::TryFrom;
use std::io::{stdin, BufRead};

fn main() {
    let n_test_cases: usize = read!();
    let mut output: Vec<u64> = initialize_empty_array(n_test_cases);

    for element in output.iter_mut() {
        let input = read_a_test_case();
        *element = calculate_minimum_cost_of_buying_gifts(input);
    }

    print_array(output);
}

fn initialize_empty_array(size: usize) -> Vec<u64> {
    let mut array: Vec<u64> = Vec::with_capacity(size);
    unsafe {
        array.set_len(size);
    }
    return array;
}

fn read_a_test_case() -> Vec<u64> {
    let [n_black_gifts, n_white_gifts] = <[u64; 2]>::try_from(read_an_array()).ok().unwrap();
    let [black_gift_cost, white_gift_cost, cost_to_convert_between_gifts] =
        <[u64; 3]>::try_from(read_an_array()).ok().unwrap();

    return vec![
        n_black_gifts,
        n_white_gifts,
        black_gift_cost,
        white_gift_cost,
        cost_to_convert_between_gifts,
    ];
}

fn read_an_array() -> Vec<u64> {
    let array: Vec<u64> = stdin()
        .lock()
        .lines()
        .next()
        .unwrap()
        .unwrap()
        .trim()
        .split(' ')
        .map(|s| s.parse().unwrap())
        .collect();
    return array;
}

fn calculate_minimum_cost_of_buying_gifts(input: Vec<u64>) -> u64 {
    if are_original_costs_cheaper_or_equal_than_convertion_between_gifts(input.clone()) {
        return calculate_minimum_standard_cost(input.clone());
    }
    return calculate_minimum_cost_in_converting_gifts(input.clone());
}

fn are_original_costs_cheaper_or_equal_than_convertion_between_gifts(input: Vec<u64>) -> bool {
    let [_, _2, black_gift_cost, white_gift_cost, cost_to_convert_between_gifts] =
        <[u64; 5]>::try_from(input).ok().unwrap();
    let cost_to_convert_from_black_to_white: u64 = black_gift_cost + cost_to_convert_between_gifts;
    let cost_to_convert_from_white_to_black: u64 = white_gift_cost + cost_to_convert_between_gifts;

    return white_gift_cost <= cost_to_convert_from_black_to_white
        && black_gift_cost <= cost_to_convert_from_white_to_black;
}

fn calculate_minimum_standard_cost(input: Vec<u64>) -> u64 {
    let [n_black_gifts, n_white_gifts, black_gift_cost, white_gift_cost, _] =
        <[u64; 5]>::try_from(input).ok().unwrap();
    return n_black_gifts * black_gift_cost + n_white_gifts * white_gift_cost;
}

fn calculate_minimum_cost_in_converting_gifts(input: Vec<u64>) -> u64 {
    let [n_black_gifts, n_white_gifts, black_gift_cost, white_gift_cost, cost_to_convert_between_gifts] =
        <[u64; 5]>::try_from(input).ok().unwrap();

    let cost_to_convert_from_black_to_white: u64 = black_gift_cost + cost_to_convert_between_gifts;
    let total_gifts: u64 = n_black_gifts + n_white_gifts;

    let minimum_cost_of_buying_gifts: u64;

    if white_gift_cost > cost_to_convert_from_black_to_white {
        minimum_cost_of_buying_gifts =
            total_gifts * black_gift_cost + n_white_gifts * cost_to_convert_between_gifts;
    } else {
        minimum_cost_of_buying_gifts =
            total_gifts * white_gift_cost + n_black_gifts * cost_to_convert_between_gifts;
    }

    return minimum_cost_of_buying_gifts;
}

fn print_array(array: Vec<u64>) {
    for element in array.iter() {
        println!("{}", element);
    }
}
