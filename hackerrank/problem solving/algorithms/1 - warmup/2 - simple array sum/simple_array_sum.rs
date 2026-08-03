// https://www.hackerrank.com/challenges/simple-array-sum/problem?isFullScreen=true

fn main() {
    let n: usize = text_io::read!();
    print!("{}", sum_stdin(n));
}

// T: O(n)
// S: O(1) extra space
fn sum_stdin(n: usize) -> i32 {
    (0..n).map(|_| -> i32 { text_io::read!() }).sum()
}
