// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

use std::collections::HashSet;

fn main() {
    let n: usize = text_io::read!();
    let beautiful_difference: i32 = text_io::read!();
    let arr: Vec<i32> = read_nums(n);
    println!("{}", find_beautiful_triplets(&arr, beautiful_difference));
}

fn read_nums(n: usize) -> Vec<i32> {
    (0..n).map(|_| text_io::read!()).collect()
}

// n: length of arr
// k: distinct numbers of arr
// k <= n
// T: O(n)
// S: O(k) = O(n) extra space
fn find_beautiful_triplets(arr: &[i32], beautiful_difference: i32) -> usize {
    let values: HashSet<_> = arr.iter().cloned().collect();
    let double_bd: i32 = 2 * beautiful_difference;
    arr.iter()
        .filter(|&x| {
            values.contains(&(x + beautiful_difference))
                && values.contains(&(x + double_bd))
        })
        .count()
}
