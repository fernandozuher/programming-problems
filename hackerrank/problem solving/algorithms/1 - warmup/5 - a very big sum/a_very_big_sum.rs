// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    print!("{}", a_very_big_sum(n));
}

fn a_very_big_sum(n: usize) -> i64 {
    let mut sum: i64 = 0;
    for _ in 0..n {
        let x: i64 = read!();
        sum += x;
    }
    return sum;
}
