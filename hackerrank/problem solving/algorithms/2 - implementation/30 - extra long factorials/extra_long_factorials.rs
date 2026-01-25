// https://www.hackerrank.com/challenges/extra-long-factorials/problem?isFullScreen=true

use num::BigUint;
use text_io::read;

fn main() {
    let n: u32 = read!();
    println!("{}", factorial(n));
}

// T: O(n)
// S: O(1) extra space (excluding the size of the resulting integer)
fn factorial(n: u32) -> BigUint {
    (1..=n).product()
}
