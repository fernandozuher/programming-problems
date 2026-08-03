// https://www.hackerrank.com/challenges/sherlock-and-squares/problem?isFullScreen=true

fn main() {
    let n: usize = text_io::read!();
    for _ in 0..n {
        let a: usize = text_io::read!();
        let b: usize = text_io::read!();
        println!("{}", squares(a, b));
    }
}

// T: O(1)
// S: O(1) extra space
fn squares(start_num: usize, end_num: usize) -> usize {
    let max_square = (end_num as f64).sqrt().floor() as usize;
    let min_square = (start_num as f64).sqrt().ceil() as usize;
    max_square - min_square + 1
}
