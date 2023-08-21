// https://www.hackerrank.com/challenges/30-loops/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: i32 = read!();
    for i in 1..=10 {
        println!("{0} x {1} = {2}", n, i, n * i);
    }
}
