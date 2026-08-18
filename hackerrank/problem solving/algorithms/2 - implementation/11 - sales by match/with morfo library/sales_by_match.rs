// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

use morfo::{counter, read_ln, skip_input_ln};
use std::collections::HashMap;

fn main() {
    skip_input_ln();
    let arr: Vec<i32> = read_ln();
    let socks_to_counts = counter(arr);
    println!("{}", sock_merchant(&socks_to_counts));
}

// k: length of entries in socks_to_counts
// T: O(k)
// S: O(1) extra space
fn sock_merchant(socks_to_counts: &HashMap<i32, usize>) -> usize {
    socks_to_counts.values().map(|x| x / 2).sum()
}
