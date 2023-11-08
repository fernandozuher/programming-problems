// https://www.hackerrank.com/challenges/30-bitwise-and/problem?isFullScreen=true

use text_io::{read, scan};

fn main() {
    let n = read!();
    for i in 0..n {
        let (count, lim): (i32, i32);
        scan!("{} {}", count, lim);
        println!("{}", bitwise_and(count, lim));
    }
}

fn bitwise_and(n: i32, k: i32) -> i32 {
    let mut maximum_value_less_than_k: i32 = 0;

    for i in 1..=n {
        for j in (i + 1)..=n {
            let operation = i & j;

            if operation < k && operation > maximum_value_less_than_k {
                if operation == k - 1 {
                    return operation;
                } else {
                    maximum_value_less_than_k = operation;
                }
            }
        }
    }

    return maximum_value_less_than_k;
}
