// Source: https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

#[macro_use]
extern crate text_io;
extern crate num_bigint;

use num_bigint::{BigUint, ToBigUint};

fn main() {
    let number: i32 = read!();
    let factorial: BigUint = calculate_factorial_of(number);
    println!("{}", factorial);
}

fn calculate_factorial_of(number: i32) -> BigUint {
    let mut factorial: BigUint = 1_i32.to_biguint().unwrap();

    for i in 2..=number {
        factorial *= i.to_biguint().unwrap();
    }

    return factorial;
}
