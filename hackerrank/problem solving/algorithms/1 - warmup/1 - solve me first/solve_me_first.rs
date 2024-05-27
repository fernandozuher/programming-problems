// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

use text_io::read;

fn main() {
    let num1: i32 = read!();
    let num2: i32 = read!();
    print!("{}", solve_me_first(num1, num2));
}

fn solve_me_first(a: i32, b: i32) -> i32 {
    return a + b;
}
