// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

use morfo::{read, read_ln, skip_input};

fn main() {
    skip_input();
    let max_jump: i32 = read();
    let hurdles: Vec<i32> = read_ln();
    println!("{}", hurdle_race(&hurdles, max_jump));
}

// n: length of hurdles
// T: O(n)
// S: O(1) extra space
fn hurdle_race(hurdles: &[i32], max_jump: i32) -> i32 {
    0.max(*hurdles.iter().max().unwrap() - max_jump)
}
