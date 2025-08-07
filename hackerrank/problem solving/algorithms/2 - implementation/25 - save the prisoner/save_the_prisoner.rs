// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

use text_io::{read, scan};

fn main() {
    let n: usize = read!();
    (0..n)
        .map(|_| {
            let (prisoners, sweets, start_chair): (i32, i32, i32);
            scan!("{} {} {}", prisoners, sweets, start_chair);
            save_the_prisoner(prisoners, sweets, start_chair)
        })
        .for_each(|x| println!("{}", x))
}

fn save_the_prisoner(prisoners: i32, sweets: i32, start_chair: i32) -> i32 {
    ((start_chair - 1 + sweets - 1) % prisoners) + 1
}
