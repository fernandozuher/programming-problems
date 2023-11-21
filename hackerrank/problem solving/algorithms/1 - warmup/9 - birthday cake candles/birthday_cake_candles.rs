// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

use std::io::{stdin, BufRead};
use text_io::read;

fn main() {
    let n: i32 = read!();
    let array: Vec<i32> = read_int_array();
    println!("{}", birthday_cake_candles(&array));
}

fn read_int_array() -> Vec<i32> {
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

fn birthday_cake_candles(candles: &Vec<i32>) -> i32 {
    let max_element: i32 = candles.iter().fold(i32::MIN, |a, b| a.max(*b));
    let count_max: i32 = candles
        .iter()
        .filter(|&number| *number == max_element)
        .count() as i32;
    return count_max;
}
