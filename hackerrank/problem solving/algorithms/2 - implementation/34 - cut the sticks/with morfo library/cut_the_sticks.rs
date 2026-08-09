// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

use morfo::{println, read_ln, skip_input_ln};

fn main() {
    skip_input_ln();
    let mut arr: Vec<usize> = read_ln();
    arr.sort();
    println(&cut_the_sticks(&arr));
}

// n: length of arr
// k: number of distinct values in arr
// k <= n
// T: O(n)
//    Sorting arr beforehand is O(n log n)
// S: O(k) = O(n) extra space
//    Sorting arr beforehand is O(n) extra space
fn cut_the_sticks(arr: &[usize]) -> Vec<usize> {
    let mut res: Vec<usize> = Vec::new();
    let (mut slow, n): (usize, usize) = (0, arr.len());

    for fast in 0..n {
        if arr[slow] == arr[fast] {
            continue;
        }
        res.push(n - slow);
        slow = fast;
    }

    res.push(n - slow);
    res
}
