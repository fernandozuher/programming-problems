// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

use morfo::{counter, read_ln, skip_input_ln};
use std::collections::HashMap;

fn main() {
    let birds_to_counts = read_input();
    println!("{}", find_most_spotted_bird(&birds_to_counts));
}

// n: length of input
// T: O(n)
// S: O(n) extra space
fn read_input() -> HashMap<i32, usize> {
    skip_input_ln();
    let ids: Vec<i32> = read_ln();
    counter(ids)
}

// n: length of birds_to_counts
// T: O(n)
// S: O(1) extra space
fn find_most_spotted_bird(birds_to_counts: &HashMap<i32, usize>) -> i32 {
    *birds_to_counts
        .iter()
        .max_by_key(|&(&id, &count)| (count, -id))
        .unwrap()
        .0
}
