// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    for _ in 0..n {
        let a: usize = read!();
        let b: usize = read!();
        println!("{}", squares(a, b));
    }
}

fn squares(start_num: usize, end_num: usize) -> usize {
    let max_square = (end_num as f64).sqrt().floor() as usize;
    let min_square = (start_num as f64).sqrt().ceil() as usize;
    max_square - min_square + 1
}
