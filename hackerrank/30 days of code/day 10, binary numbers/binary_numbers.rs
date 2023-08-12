// https://www.hackerrank.com/challenges/30-binary-numbers/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

use std::cmp::max;

fn main() {
    let mut n: i32 = read!();
    let (mut max_ones, mut ones): (i32, i32) = (0, 0);

    while n > 0 {
        if n % 2 == 1 {
            ones += 1;
        } else {
            max_ones = max(ones, max_ones);
            ones = 0
        }
        n /= 2;
    }

    max_ones = max(max_ones, ones);
    println!("{}", max_ones);
}
