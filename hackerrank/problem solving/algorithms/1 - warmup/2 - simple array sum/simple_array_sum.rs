// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

use std::io::{stdin, BufRead};
use text_io::read;

fn main() {
    let _n: i32 = read!();
    let array: Vec<i32> = read_int_array();
    println!("{}", simple_array_sum(&array));
}

fn read_int_array() -> Vec<i32> {
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

fn simple_array_sum(array: &Vec<i32>) -> i32 {
    return array.iter().sum();
}
