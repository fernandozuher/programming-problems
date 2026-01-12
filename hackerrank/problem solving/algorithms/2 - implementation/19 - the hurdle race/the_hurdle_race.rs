// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let max_jump: i32 = read!();
    let hurdles = read_numbers(n);
    println!("{}", hurdle_race(&hurdles, max_jump));
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

// n: length of array hurdles
// T: O(n)
// S: O(1) extra space
fn hurdle_race(hurdles: &[i32], max_jump: i32) -> i32 {
    0.max(*hurdles.iter().max().unwrap() - max_jump)
}
