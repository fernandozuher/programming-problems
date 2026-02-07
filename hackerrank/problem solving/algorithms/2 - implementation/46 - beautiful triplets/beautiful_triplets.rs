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

// n: length of array arr
// T: O(n)
// S: O(n) extra space
fn find_beautiful_triplets(arr: &[i32], beautiful_difference: i32) -> usize {
    let values: HashSet<_> = arr.iter().cloned().collect();
    let double_bd: i32 = 2 * beautiful_difference;
    arr.iter()
        .filter(|&x| {
            values.contains(&(x + beautiful_difference))
                && values.contains(&(x + double_bd))
        })
        .count()
}
