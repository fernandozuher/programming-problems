// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let candles: Vec<i32> = read_numbers(n);
    println!("{}", birthday_cake_candles(candles));
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn birthday_cake_candles(candles: Vec<i32>) -> usize {
    let max = candles.iter().max().unwrap();
    candles.iter().filter(|&x| x == max).count()
}
