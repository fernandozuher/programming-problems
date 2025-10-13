// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

use std::collections::HashSet;
use text_io::read;

fn main() {
    let n: usize = read!();
    let beautiful_difference: i32 = read!();
    let arr: Vec<i32> = read_numbers(n);
    println!("{}", find_beautiful_triplets(&arr, beautiful_difference));
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn find_beautiful_triplets(arr: &[i32], beautiful_difference: i32) -> usize {
    let values: HashSet<_> = arr.iter().cloned().collect();
    arr.iter()
        .filter(|&x| {
            values.contains(&(x + beautiful_difference))
                && values.contains(&(x + 2 * beautiful_difference))
        })
        .count()
}
