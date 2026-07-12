// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    print!("{}", sum_stdin(n));
}

// T: O(n)
// S: O(1) extra space
fn sum_stdin(n: usize) -> i32 {
    (0..n).map(|_| -> i32 { read!() }).sum()
}
