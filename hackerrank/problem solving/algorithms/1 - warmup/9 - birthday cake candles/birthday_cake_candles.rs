// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    print!("{}", birthday_cake_candles(n));
}

fn birthday_cake_candles(n: usize) -> i32 {
    let mut max_element: i32 = 0;
    let mut max_count: i32 = 0;

    for _ in 0..n {
        let x: i32 = read!();
        if x > max_element {
            max_element = x;
            max_count = 1;
        } else if x == max_element {
            max_count += 1;
        }
    }

    return max_count;
}
