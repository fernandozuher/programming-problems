// https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

use std::collections::HashMap;
use text_io::read;

fn main() {
    let n: usize = read!();
    println!("{}", picking_numbers(&read_numbers_into_map(n)));
}

fn read_numbers_into_map(n: usize) -> HashMap<i32, i32> {
    let mut counter: HashMap<i32, i32> = HashMap::new();
    for _ in 0..n {
        *counter.entry(read!()).or_insert(0) += 1;
    }
    counter
}

fn picking_numbers(counter: &HashMap<i32, i32>) -> i32 {
    let mut max_len = 0;
    for &num in counter.keys() {
        let mut current = counter[&num];
        current += counter.get(&(num + 1)).cloned().unwrap_or(0);
        max_len = max_len.max(current);
    }
    max_len
}
