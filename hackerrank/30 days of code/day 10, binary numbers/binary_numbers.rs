// https://www.hackerrank.com/challenges/30-binary-numbers/problem?is_full_screen=true

use std::cmp::max;
use text_io::read;

fn main() {
    let n: i32 = read!();
    let binary = format!("{:b}", n);
    println!("{}", max_consecutive_ones_from(binary));
}

fn max_consecutive_ones_from(binary: String) -> usize {
    let mut max_1_bits: usize = 0;
    let mut i: usize = 0;
    while i < binary.len() {
        if binary.as_bytes()[i] == b'1' {
            let n_bits = size_of_next_range_of_bits_1(&binary, i);
            max_1_bits = max(n_bits, max_1_bits);
            i += n_bits
        }
        i += 1;
    }
    max_1_bits
}

fn size_of_next_range_of_bits_1(binary: &String, begin_index: usize) -> usize {
    let next_after_last_index = find_next_after_last_index_of_consecutive_1s(binary, begin_index);
    next_after_last_index - begin_index
}

fn find_next_after_last_index_of_consecutive_1s(binary: &String, begin_index: usize) -> usize {
    let next_after_last_index = binary.get(begin_index..).and_then(|s| s.find('0'));
    if next_after_last_index == None {
        return binary.len();
    }
    // + begin_index because index was found from that, not from index 0
    next_after_last_index.unwrap() + begin_index
}
