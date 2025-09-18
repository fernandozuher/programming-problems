// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

use std::cmp::min;
use text_io::read;

fn main() {
    let initial_string: String = read!();
    let final_string: String = read!();
    let n_operations: usize = read!();
    let res = if append_and_delete(initial_string.as_str(), final_string.as_str(), n_operations) {
        "Yes"
    } else {
        "No"
    };
    println!("{}", res);
}

fn append_and_delete(s1: &str, s2: &str, n_ops: usize) -> bool {
    let prefix_len: usize = common_prefix_length(s1, s2);
    let total_ops_needed = (s1.len() - prefix_len) + (s2.len() - prefix_len);
    let can_remove_all = n_ops >= s1.len() + s2.len();
    can_remove_all || (n_ops >= total_ops_needed && (n_ops - total_ops_needed) % 2 == 0)
}

fn common_prefix_length(s1: &str, s2: &str) -> usize {
    let min_len: usize = min(s1.len(), s2.len());
    for i in 0..min_len {
        if s1.as_bytes()[i] != s2.as_bytes()[i] {
            return i;
        }
    }
    min_len
}
