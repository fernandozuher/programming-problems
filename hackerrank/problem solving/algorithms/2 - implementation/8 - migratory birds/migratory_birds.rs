// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

use std::collections::HashMap;
use text_io::read;

fn main() {
    let n: usize = read!();
    let birds = read_numbers(n);
    println!("{}", find_most_spotted_bird(&birds));
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn find_most_spotted_bird(birds: &[i32]) -> i32 {
    let mut bird_count = HashMap::new();
    for &bird in birds {
        *bird_count.entry(bird).or_insert(0) += 1;
    }

    *bird_count
        .iter()
        .max_by_key(|(&id, &count)| (count, (count, std::cmp::Reverse(id))))
        .unwrap()
        .0
}
