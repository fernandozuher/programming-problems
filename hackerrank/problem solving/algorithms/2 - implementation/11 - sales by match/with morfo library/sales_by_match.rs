// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

use morfo::{read_ln, skip_input_ln};
use std::collections::HashMap;

fn main() {
    skip_input_ln();
    let arr: Vec<i32> = read_ln();
    println!("{}", sock_merchant(&counter(&arr)));
}

// n: length of arr
// k: length of distinct numbers in arr
// k <= n
// T: O(n)
// S: O(k) extra space
fn counter(arr: &[i32]) -> HashMap<i32, i32> {
    let mut freq_map = HashMap::new();
    for &x in arr {
        *freq_map.entry(x).or_insert(0) += 1;
    }
    freq_map
}

// k: length of entries in socks_to_counts
// T: O(k)
// S: O(1) extra space
fn sock_merchant(socks_to_counts: &HashMap<i32, i32>) -> i32 {
    socks_to_counts.values().map(|x| x / 2).sum()
}
