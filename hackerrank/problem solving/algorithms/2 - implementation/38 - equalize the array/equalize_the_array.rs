// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

use counter::Counter;
use text_io::read;

fn main() {
    let n: usize = read!();
    println!("{}", min_deletions_to_equalize(&*read_numbers(n)));
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

// n: length of arr, 1 <= n <= 100
// T: O(n) = O(100) = O(1)
// S: O(n) = O(100) = O(1) extra space
fn min_deletions_to_equalize(arr: &[i32]) -> usize {
    let counter: Counter<&i32> = Counter::from_iter(arr);
    let max_count = counter
        .iter()
        .max_by_key(|(_k, v)| *v)
        .unwrap_or((&&0, &0))
        .1;
    arr.len() - max_count
}
