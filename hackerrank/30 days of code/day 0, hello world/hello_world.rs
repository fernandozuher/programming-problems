// https://www.hackerrank.com/challenges/30-hello-world/problem?isFullScreen=true

use text_io::read;

fn main() {
    println!("Hello, World.");
    let input: String = read!("{}\n");
    println!("{}", input);
}
