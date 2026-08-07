// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

use morfo::{read_ln, skip_input_ln};

fn main() {
    skip_input_ln();
    let candles: Vec<i32> = read_ln();
    println!("{}", birthday_cake_candles(&candles));
}

// n: length of candles
// T: O(2n) => O(n)
// S: O(1) extra space
fn birthday_cake_candles(candles: &[i32]) -> usize {
    let max = candles.iter().max().unwrap();
    candles.iter().filter(|&x| x == max).count()
}
