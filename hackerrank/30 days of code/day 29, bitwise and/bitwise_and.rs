// https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

use text_io::{read, scan};

fn main() {
    let test_cases: usize = read!();
    for _ in 0..test_cases {
        let (n, k): (i32, i32);
        scan!("{} {}", n, k);
        println!("{}", bitwise_and(n, k));
    }
}

fn bitwise_and(n: i32, k: i32) -> i32 {
    if (k - 1 | k) <= n {
        k - 1
    } else {
        k - 2
    }
}
