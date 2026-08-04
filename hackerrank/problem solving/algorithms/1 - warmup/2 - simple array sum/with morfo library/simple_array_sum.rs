// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

use morfo::{read, read_ln_iter};

fn main() {
    let n: usize = read();
    print!("{}", sum_stdin(n));
}

// T: O(n)
// S: O(1) extra space
fn sum_stdin(n: usize) -> i32 {
    read_ln_iter::<i32>().sum()
}
