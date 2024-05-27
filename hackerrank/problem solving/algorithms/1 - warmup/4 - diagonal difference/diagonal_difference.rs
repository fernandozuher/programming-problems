// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    print!("{}", diagonal_difference(n));
}

fn diagonal_difference(n: usize) -> i32 {
    let (mut primary_diagonal, mut secondary_diagonal) = (0, 0);

    for i in 0..n {
        for j in 0..n {
            let x: i32 = read!();
            if i == j {
                primary_diagonal += x;
            }
            if j == n - i - 1 {
                secondary_diagonal += x;
            }
        }
    }

    return (primary_diagonal - secondary_diagonal).abs();
}
