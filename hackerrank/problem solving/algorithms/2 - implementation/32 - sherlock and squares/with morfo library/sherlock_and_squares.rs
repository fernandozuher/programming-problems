// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

use morfo::{read, read_many};

fn main() {
    let n: usize = read();
    for _ in 0..n {
        let (a, b): (i64, i64) = read_many();
        println!("{}", squares(a, b));
    }
}

// T: O(1)
// S: O(1) extra space
fn squares(start_num: i64, end_num: i64) -> i64 {
    let max_square = (end_num as f64).sqrt().floor() as i64;
    let min_square = (start_num as f64).sqrt().ceil() as i64;
    max_square - min_square + 1
}
