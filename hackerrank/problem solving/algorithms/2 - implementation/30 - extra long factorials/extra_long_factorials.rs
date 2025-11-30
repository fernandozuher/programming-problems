// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

use num::BigUint;
use text_io::read;

fn main() {
    let n: u32 = read!();
    println!("{}", factorial(n));
}

fn factorial(n: u32) -> BigUint {
    (1..=n).product()
}
