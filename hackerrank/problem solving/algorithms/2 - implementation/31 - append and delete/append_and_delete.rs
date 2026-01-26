// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

use text_io::read;

fn main() {
    let s1: String = read!();
    let s2: String = read!();
    let n_ops: usize = read!();
    if append_and_delete(s1.as_str(), s2.as_str(), n_ops) {
        println!("{}", "Yes");
    } else {
        println!("{}", "No");
    }
}

// n1: length of string s1
// n2: length of string s2
// T: O(min(n1, n2))
// S: O(1) extra space
fn append_and_delete(s1: &str, s2: &str, n_ops: usize) -> bool {
    let prefix_len: usize = common_prefix_length(s1, s2);
    let ops_needed: usize = (s1.len() - prefix_len) + (s2.len() - prefix_len);
    if n_ops < ops_needed {
        return false;
    }

    if n_ops >= s1.len() + s2.len() {
        return true;
    }

    (n_ops - ops_needed) % 2 == 0
}

fn common_prefix_length(s1: &str, s2: &str) -> usize {
    s1.as_bytes()
        .iter()
        .zip(s2.as_bytes().iter())
        .position(|(x, y)| x != y)
        .unwrap_or_else(|| s1.len().min(s2.len()))
}
