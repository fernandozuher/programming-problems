// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    staircase(n);
}

fn staircase(n: usize) {
    for i in 1..=n {
        for j in 0..n - i {
            print!(" ");
        }
        for k in 0..i {
            print!("#");
        }
        println!();
    }
}
