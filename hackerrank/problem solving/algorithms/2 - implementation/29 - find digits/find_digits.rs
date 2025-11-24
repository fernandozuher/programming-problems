// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    for _ in 0..n {
        println!("{}", find_digits(read!()));
    }
}

fn find_digits(n: i32) -> usize {
    n.to_string()
        .chars()
        .map(|c| c.to_digit(10).unwrap())
        .filter(|&d| d != 0 && n % (d as i32) == 0)
        .count()
}
