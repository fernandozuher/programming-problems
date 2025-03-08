// https://www.hackerrank.com/challenges/30-binary-numbers/problem?is_full_screen=true

use std::cmp::max;
use text_io::read;

fn main() {
    let n: i32 = read!();
    let binary: String = int_to_binary(n);
    println!("{}", find_size_widest_range_bits_1_from(&binary));
}

fn int_to_binary(n: i32) -> String {
    format!("{:b}", n)
}

fn find_size_widest_range_bits_1_from(binary: &str) -> usize {
    let mut size_widest_range: usize = 0;
    let mut i: usize = 0;
    while i < binary.len() {
        if binary.as_bytes()[i] == b'1' {
            let binary_from_i: &str = &binary[i..];
            let size_range: usize = find_size_next_range_bits_1_from(binary_from_i);
            size_widest_range = max(size_range, size_widest_range);
            i += size_range
        }
        i += 1;
    }
    size_widest_range
}

fn find_size_next_range_bits_1_from(binary: &str) -> usize {
    binary.find('0').unwrap_or(binary.len())
}
