// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

use std::io::{stdin, BufRead};
use text_io::read;

fn main() {
    let n: i32 = read!();
    let array: Vec<i32> = read_int_array();
    plus_minus(&array);
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

fn plus_minus(array: &Vec<i32>) {
    let mut positive: i32 = 0;
    let mut negative: i32 = 0;
    let mut zero: i32 = 0;

    for number in array {
        if number > &0 {
            positive += 1;
        } else if number < &0 {
            negative += 1;
        } else {
            zero += 1;
        }
    }

    let n = array.len() as f32;
    let positive_proportion = (positive as f32) / n;
    let negative_proportion = (negative as f32) / n;
    let zero_proportion = (zero as f32) / n;

    println!("{:.6}", positive_proportion);
    println!("{:.6}", negative_proportion);
    println!("{:.6}", zero_proportion);
}
