// https://www.hackerrank.com/challenges/sock-merchant/problem?isFullScreen=true

use std::collections::HashMap;
use text_io::read;

fn main() {
    let n: usize = read!();
    let sock_counts: HashMap<i32, i32> = read_numbers_into_map(n);
    println!("{}", sock_merchant(&sock_counts));
}

fn read_numbers_into_map(n: usize) -> HashMap<i32, i32> {
    let mut number_counts = HashMap::new();
    for _ in 0..n {
        let x: i32 = read!();
        *number_counts.entry(x).or_insert(0) += 1;
    }
    number_counts
}

fn sock_merchant(sock_counts: &HashMap<i32, i32>) -> i32 {
    sock_counts.values().fold(0, |pairs, count| pairs + count / 2)
}
