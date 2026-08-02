// https://www.hackerrank.com/challenges/solve-me-first/problem?isFullScreen=true

fn main() {
    let n1: i32 = text_io::read!();
    let n2: i32 = text_io::read!();
    print!("{}", solve_me_first(n1, n2));
}

// T: O(1)
// S: O(1) extra space
fn solve_me_first(n1: i32, n2: i32) -> i32 {
    n1 + n2
}
