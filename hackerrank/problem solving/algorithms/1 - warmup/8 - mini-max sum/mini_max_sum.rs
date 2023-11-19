// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

use std::io::{stdin, BufRead};

fn main() {
    let mut array: Vec<i64> = read_int_array();
    array.sort();
    mini_max_sum(&array);
}

fn read_int_array() -> Vec<i64> {
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

fn mini_max_sum(array: &Vec<i64>) {
    let mut total_sum: i64 = 0;
    for n in array.iter() {
        total_sum += *n;
    }

    let min_sum: i64 = total_sum - array[array.len() - 1];
    let max_sum: i64 = total_sum - array[0];
    println!("{} {}", min_sum, max_sum);
}
