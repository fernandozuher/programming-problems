// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

use morfo::{read_ln, reduce_many};
use std::cmp::{max, min};

fn main() {
    let arr: Vec<i64> = read_ln();
    let (min_sum, max_sum) = calc_min_max_sum(&arr);
    print!("{} {}", min_sum, max_sum);
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
fn calc_min_max_sum(arr: &[i64]) -> (i64, i64) {
    let (total, min_value, max_value) = morfo::reduce_many!(
        arr,
        add, 0,
        smaller, arr[0],
        larger, arr[0],
    );

    (total - max_value, total - min_value)
}

fn add(a: i64, &b: &i64) -> i64 {
    a + b
}

fn smaller(a: i64, &b: &i64) -> i64 {
    min(a, b)
}

fn larger(a: i64, &b: &i64) -> i64 {
    max(a, b)
}
