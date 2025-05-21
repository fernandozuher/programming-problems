// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    println!("{}", diagonal_difference(n));
}

fn diagonal_difference(n: usize) -> i32 {
    let (mut primary_sum, mut secondary_sum) = (0, 0);

    for i in 0..n {
        let numbers = read_numbers(n);
        primary_sum += numbers[i];
        secondary_sum += numbers[n - i - 1];
    }

    (primary_sum - secondary_sum).abs()
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}
