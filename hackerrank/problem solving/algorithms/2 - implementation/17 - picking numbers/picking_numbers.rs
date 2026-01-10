// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

use std::collections::HashMap;
use text_io::read;

fn main() {
    let n: usize = read!();
    println!("{}", picking_numbers(&counter(n)));
}

fn counter(n: usize) -> HashMap<i32, i32> {
    let mut frequency: HashMap<i32, i32> = HashMap::new();
    for _ in 0..n {
        *frequency.entry(read!()).or_insert(0) += 1;
    }
    frequency
}

// n: length of initial input array of numbers
// k: length of map frequency
// T:
//   Without constraining the input values:
//       In the worst case, length of map equals length of initial input array when there is no repeated element: k = n
//       O(n)
//   With input values limited to 1 through 99, as stated in the problem:
//       Max of 99 keys/values at map: O(99) = O(1)
// S: O(1) extra space
fn picking_numbers(frequency: &HashMap<i32, i32>) -> i32 {
    let mut max_len = 0;
    for &num in frequency.keys() {
        let current = frequency[&num] + frequency.get(&(num + 1)).cloned().unwrap_or(0);
        max_len = max_len.max(current);
    }
    max_len
}
