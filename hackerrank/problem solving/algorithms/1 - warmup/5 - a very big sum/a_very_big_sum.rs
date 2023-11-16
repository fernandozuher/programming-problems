// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

use std::io::{stdin, BufRead};
use text_io::read;

fn main() {
    let n: i32 = read!();
    let array: Vec<i64> = read_an_int_array();
    println!("{}", a_very_big_sum(&array));
}

fn read_an_int_array() -> Vec<i64> {
    return stdin()
        .lock()
        .lines()
        .next()
        .unwrap()
        .unwrap()
        .trim()
        .split(' ')
        .map(|s| s.parse().unwrap())
        .collect();
}

fn a_very_big_sum(array: &Vec<i64>) -> i64 {
    return array.iter().sum();
}
