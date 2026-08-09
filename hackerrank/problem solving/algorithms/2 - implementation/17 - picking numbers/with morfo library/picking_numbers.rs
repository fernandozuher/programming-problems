// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

use morfo::{read_ln, skip_input_ln};
use std::collections::HashMap;

fn main() {
    skip_input_ln();
    let arr: Vec<i32> = read_ln();
    println!("{}", picking_numbers(&counter(&arr)));
}

// n: length of arr
// T: O(n)
// S: O(n) extra space
fn counter(arr: &[i32]) -> HashMap<i32, i32> {
    let mut freq_map = HashMap::new();
    for &num in arr {
        *freq_map.entry(num).or_insert(0) += 1;
    }
    freq_map
}

// k: length of freq_map
// 1 <= k <= 99
// T: O(k) = O(99) = O(1)
// S: O(1) extra space
fn picking_numbers(freq_map: &HashMap<i32, i32>) -> i32 {
    let mut max_len = 0;
    for (&num, &count) in freq_map.iter() {
        let current = count + freq_map.get(&(num + 1)).copied().unwrap_or(0);
        max_len = max_len.max(current);
    }
    max_len
}
