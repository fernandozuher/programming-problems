// https://www.hackerrank.com/challenges/30-conditional-statements/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: i32 = read!();
    let is_weird: bool = n & 1 == 1 || n >= 6 && n <= 20;
    if is_weird {
        println!("Weird");
    } else {
        println!("Not Weird");
    }
}
