// https://www.hackerrank.com/challenges/30-binary-numbers/problem?is_full_screen=true

use std::cmp::max;
use text_io::read;

fn main() {
    let n: i32 = read!();
    let binary: String = format!("{:b}", n);
    println!("{}", find_max_length_of_ones(&binary));
}

fn find_max_length_of_ones(binary: &str) -> usize {
    binary.split('0').map(|segment| segment.len()).max().unwrap_or(0)
}
