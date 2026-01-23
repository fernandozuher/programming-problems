// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    for _ in 0..n {
        let num: i32 = read!();
        println!("{}", find_digits(num));
    }
}

// k: quantity of digits of num = log num
// 0 < num < 10^9
// T: O(k) = O(9) = O(1)
// S: O(k) = O(9) = O(1) extra space
fn find_digits(num: i32) -> usize {
    num.to_string()
        .chars()
        .map(|c| c.to_digit(10).unwrap())
        .filter(|&d| d != 0 && num % (d as i32) == 0)
        .count()
}
