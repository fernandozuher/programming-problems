// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: i32 = read!();
    staircase(n);
}

fn staircase(n: i32) {
    for i in 1..=n {
        for j in 0..n - i {
            print!(" ");
        }
        for k in 0..i {
            print!("#");
        }
        print!("\n");
    }
}
