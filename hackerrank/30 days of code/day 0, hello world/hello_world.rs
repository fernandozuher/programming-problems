// https://www.hackerrank.com/challenges/30-hello-world/problem?isFullScreen=true

use text_io::read;

fn main() {
    let input: String = read!("{}\n");
    println!("Hello, World.");
    println!("{}", input);
}
