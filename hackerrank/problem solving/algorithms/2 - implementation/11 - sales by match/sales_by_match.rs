// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

use std::collections::HashMap;
use text_io::read;

fn main() {
    let n: usize = read!();
    let sock_counts: HashMap<i32, i32> = counter(n);
    println!("{}", sock_merchant(&sock_counts));
}

fn counter(n: usize) -> HashMap<i32, i32> {
    let mut counter = HashMap::new();
    for _ in 0..n {
        let x: i32 = read!();
        *counter.entry(x).or_insert(0) += 1;
    }
    counter
}

// n: quantity of entries in sock_counts
// T: O(n)
// S: O(1) extra space
fn sock_merchant(sock_counts: &HashMap<i32, i32>) -> i32 {
    sock_counts
        .values()
        .fold(0, |pairs, count| pairs + count / 2)
}
