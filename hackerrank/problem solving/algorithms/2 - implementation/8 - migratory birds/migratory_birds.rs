// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

use std::cmp::Reverse;
use std::collections::HashMap;
use text_io::read;

fn main() {
    let n: usize = read!();
    let bird_counts = counter(n);
    println!("{}", find_most_spotted_bird(&bird_counts));
}

fn counter(n: usize) -> HashMap<i32, i32> {
    let mut number_counts = HashMap::new();
    for _ in 0..n {
        let id: i32 = read!();
        *number_counts.entry(id).or_insert(0) += 1;
    }
    number_counts
}

fn find_most_spotted_bird(bird_counts: &HashMap<i32, i32>) -> i32 {
    bird_counts
        .iter()
        .max_by_key(|(&id, &count)| (count, Reverse(id)))
        .map(|(&id, _)| id)
        .unwrap()
}
