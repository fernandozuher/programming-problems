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
    let mut positive_quantity: i32 = 0;
    let mut negative_quantity: i32 = 0;
    let mut zero_quantity: i32 = 0;

    for number in array {
        if number > &0 {
            positive_quantity += 1;
        } else if number < &0 {
            negative_quantity += 1;
        } else {
            zero_quantity += 1;
        }
    }

    let n = array.len() as f32;
    let positive_values_proportion = (positive_quantity as f32) / n;
    let negative_values_proportion = (negative_quantity as f32) / n;
    let zero_values_proportion = (zero_quantity as f32) / n;

    println!("{:.6}", positive_values_proportion);
    println!("{:.6}", negative_values_proportion);
    println!("{:.6}", zero_values_proportion);
}
