// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

fn main() {
    let n: usize = text_io::read!();
    let candles: Vec<i32> = read_nums(n);
    println!("{}", birthday_cake_candles(&candles));
}

fn read_nums(n: usize) -> Vec<i32> {
    (0..n).map(|_| text_io::read!()).collect()
}

// n: length of candles
// T: O(2n) => O(n)
// S: O(1) extra space
fn birthday_cake_candles(candles: &[i32]) -> usize {
    let max = candles.iter().max().unwrap();
    candles.iter().filter(|&x| x == max).count()
}
