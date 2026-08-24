// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

use morfo::{counter, read_ln, skip_input_ln};

fn main() {
    skip_input_ln();
    let arr: Vec<i32> = read_ln();
    println!("{}", min_deletions_to_equalize(&arr));
}

// n: length of arr, 1 <= n <= 100
// k: number of distinct elements in arr
// k <= n
// T: O(n) = O(100) = O(1)
// S: O(k) = O(n) = O(100) = O(1) extra space
fn min_deletions_to_equalize(arr: &[i32]) -> usize {
    let freq_map = counter(arr.iter().copied());
    arr.len() - freq_map.values().max().copied().unwrap_or(0)
}
