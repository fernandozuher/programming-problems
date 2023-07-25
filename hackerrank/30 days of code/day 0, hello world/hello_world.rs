// https://www.hackerrank.com/challenges/30-hello-world/problem?isFullScreen=true

use std::io::{self, BufRead};

fn main() {
    let mut input_string = String::new();
    io::stdin().lock().read_line(&mut input_string).unwrap();
    println!("Hello, World.");
    println!("{}", input_string);
}
