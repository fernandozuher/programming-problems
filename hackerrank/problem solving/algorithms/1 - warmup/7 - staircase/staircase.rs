// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    staircase(n);
}

// T: O(n^2)
// S: O(n) extra space
fn staircase(n: usize) {
    for i in 1..=n {
        let spaces = " ".repeat(n - i);
        let hashes = "#".repeat(i);
        println!("{}{}", spaces, hashes);
    }
}
