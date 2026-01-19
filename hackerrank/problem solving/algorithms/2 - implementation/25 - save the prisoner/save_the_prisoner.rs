// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

use text_io::{read, scan};

fn main() {
    let n: usize = read!();
    for _ in 0..n {
        let (prisoners, sweets, start_chair): (i32, i32, i32);
        scan!("{} {} {}", prisoners, sweets, start_chair);
        println!("{}", save_the_prisoner(prisoners, sweets, start_chair));
    }
}

// T: O(1)
// S: O(1) extra space
fn save_the_prisoner(prisoners: i32, sweets: i32, start_chair: i32) -> i32 {
    ((start_chair - 1 + sweets - 1) % prisoners) + 1
}
