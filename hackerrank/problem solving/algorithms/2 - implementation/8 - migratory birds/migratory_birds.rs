// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

use std::collections::HashMap;
use text_io::read;

fn main() {
    let n: usize = read!();
    let birds_to_counts = counter(n);
    println!("{}", find_most_spotted_bird(&birds_to_counts));
}

// n: length of input
// k: length of distinct numbers
// T: O(n)
// S: O(k) = O(n) extra space
fn counter(n: usize) -> HashMap<i32, i32> {
    let mut freq_map = HashMap::new();
    for _ in 0..n {
        let x: i32 = read!();
        *freq_map.entry(x).or_insert(0) += 1;
    }
    freq_map
}

// n: length of input
// k: length of hash birds_to_counts
// T: O(k) = O(n)
// S: O(1) extra space
fn find_most_spotted_bird(birds_to_counts: &HashMap<i32, i32>) -> i32 {
    *birds_to_counts
        .iter()
        .max_by_key(|(&bird, &count)| (count, -bird))
        .unwrap()
        .0
}
