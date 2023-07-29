// https://www.hackerrank.com/challenges/30-conditional-statements/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

fn main() {
    let n: i32 = read!();

    if n & 1 == 1 || n >= 6 && n <= 20 {
        println!("Weird");
    } else {
        println!("Not Weird");
    }
}
