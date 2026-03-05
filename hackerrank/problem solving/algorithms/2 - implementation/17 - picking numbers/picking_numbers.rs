// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

use counter::Counter;
use text_io::read;

fn main() {
    let n: usize = read!();
    println!("{}", picking_numbers(&counter(n)));
}

// n: length of initial input array of numbers
// k: length of freq_map
// k <= n
// T: O(n)
// S: O(k) = O(n) extra space
fn counter(n: usize) -> Counter<i32, i32> {
    let mut freq_map = Counter::<i32, i32>::new();
    for _ in 0..n {
        freq_map[&read!()] += 1;
    }
    freq_map
}

// k: length of freq_map
// 1 <= k <= 99
// T: O(k) = O(99) = O(1)
// S: O(1) extra space
fn picking_numbers(freq_map: &Counter<i32, i32>) -> i32 {
    let mut max_len = 0;
    for &num in freq_map.keys() {
        let current = freq_map[&num] + freq_map.get(&(num + 1)).cloned().unwrap_or(0);
        max_len = max_len.max(current);
    }
    max_len
}
