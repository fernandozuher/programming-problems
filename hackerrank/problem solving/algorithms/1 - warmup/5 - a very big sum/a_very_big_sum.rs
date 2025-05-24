// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    println!("{}", a_very_big_sum(n));
}

fn a_very_big_sum(n: usize) -> i64 {
    (0..n).map(|_| read!()).collect::<Vec<i64>>().iter().sum()
}
