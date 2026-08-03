// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

fn main() {
    let n: usize = text_io::read!();
    let page: usize = text_io::read!();
    println!("{}", page_count(n, page));
}

// T: O(1)
// S: O(1) extra space
fn page_count(n: usize, page: usize) -> usize {
    let from_front: usize = page / 2;
    let from_back: usize = n / 2 - from_front;
    from_front.min(from_back)
}
