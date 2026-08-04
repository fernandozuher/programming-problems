// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

use morfo::{read, readln};

fn main() {
    let n: usize = morfo::read();
    println!("{}", diagonal_difference(n));
}

// T: O(n^2)
// S: O(n) extra space
fn diagonal_difference(n: usize) -> i32 {
    let (mut primary_sum, mut secondary_sum) = (0, 0);

    for i in 0..n {
        let arr: Vec<i32> = morfo::readln();
        primary_sum += arr[i];
        secondary_sum += arr[n - i - 1];
    }

    (primary_sum - secondary_sum).abs()
}
