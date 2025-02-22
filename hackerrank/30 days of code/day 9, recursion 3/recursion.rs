// https://www.hackerrank.com/challenges/30-recursion/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: i32 = read!();
    println!("{}", factorial(n));
}

fn factorial(n: i32) -> i32 {
    if n == 1 {
        return 1;
    }
    n * factorial(n - 1)
}
