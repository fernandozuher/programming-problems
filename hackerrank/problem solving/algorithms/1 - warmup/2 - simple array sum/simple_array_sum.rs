// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    print!("{}", sum_stdin(n));
}

fn sum_stdin(n: usize) -> i32 {
    let mut sum: i32 = 0;
    for _ in 0..n {
        let x: i32 = read!();
        sum += x;
    }
    sum
}
