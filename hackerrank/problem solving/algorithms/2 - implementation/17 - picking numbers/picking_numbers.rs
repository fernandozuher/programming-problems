// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

use std::collections::HashMap;
use text_io::read;

fn main() {
    let n: usize = read!();
    println!("{}", picking_numbers(&read_numbers(n)));
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn picking_numbers(numbers: &[i32]) -> i32 {
    let mut counter: HashMap<i32, i32> = HashMap::new();
    for &num in numbers {
        *counter.entry(num).or_insert(0) += 1;
    }

    let mut max_len = 0;
    for &num in counter.keys() {
        let mut current = counter[&num];
        current += counter.get(&(num + 1)).cloned().unwrap_or(0);
        max_len = max_len.max(current);
    }

    max_len
}
