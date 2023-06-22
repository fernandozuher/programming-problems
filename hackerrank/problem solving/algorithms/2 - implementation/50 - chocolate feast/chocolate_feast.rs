// Source: https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

use std::convert::TryFrom;
use std::io::{stdin, BufRead};

fn main() {
    let n_test_cases: usize = read!();
    let output: Vec<i32> = solve_test_cases(n_test_cases);
    for element in output.iter() {
        println!("{}", element);
    }
}

fn read_an_int_array() -> Vec<i32> {
    let array: Vec<i32> = stdin()
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

fn solve_test_cases(n_test_cases: usize) -> Vec<i32> {
    let mut output: Vec<i32> = Vec::with_capacity(n_test_cases);
    unsafe { output.set_len(n_test_cases) };

    for single_output in output.iter_mut() {
        let [amount_of_money, chocolate_bar_cost, n_wrappers_to_turn_in_bar] =
            <[i32; 3]>::try_from(read_an_int_array()).ok().unwrap();

        *single_output = how_many_chocolates_can_be_eaten(
            amount_of_money,
            chocolate_bar_cost,
            n_wrappers_to_turn_in_bar,
        );
    }

    return output;
}

fn how_many_chocolates_can_be_eaten(
    amount_of_money: i32,
    chocolate_bar_cost: i32,
    n_wrappers_to_turn_in_bar: i32,
) -> i32 {
    let mut eaten_chocolates: i32 = amount_of_money / chocolate_bar_cost;
    let mut available_wrappers: i32 = eaten_chocolates;

    while available_wrappers >= n_wrappers_to_turn_in_bar {
        let chocolates_for_free: i32 = available_wrappers / n_wrappers_to_turn_in_bar;
        available_wrappers = available_wrappers - (chocolates_for_free * n_wrappers_to_turn_in_bar)
            + chocolates_for_free;
        eaten_chocolates += chocolates_for_free;
    }

    return eaten_chocolates;
}
