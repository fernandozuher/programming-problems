// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n1: i32 = read!();
    let n2: i32 = read!();
    print!("{}", solve_me_first(n1, n2));
}

fn solve_me_first(n1: i32, n2: i32) -> i32 {
    n1 + n2
}
