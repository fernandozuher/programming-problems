// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

use text_io::{read, scan};

fn main() {
    let n: usize = read!();
    let page: usize = read!();
    println!("{}", page_count(n, page));
}

fn page_count(n: usize, page: usize) -> usize {
    let from_front: usize = page / 2;
    let from_back: usize = n / 2 - from_front;
    from_front.min(from_back)
}
