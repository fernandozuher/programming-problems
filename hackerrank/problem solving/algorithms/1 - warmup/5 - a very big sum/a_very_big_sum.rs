// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let arr: Vec<i64> = read_numbers(n);
    println!("{}", a_very_big_sum(&arr));
}

fn read_numbers(n: usize) -> Vec<i64> {
    (0..n).map(|_| read!()).collect()
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
fn a_very_big_sum(arr: &[i64]) -> i64 {
    arr.iter().sum()
}
