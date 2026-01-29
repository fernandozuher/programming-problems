// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut arr: Vec<usize> = read_numbers(n);
    arr.sort();
    for x in cut_the_sticks(&arr) {
        println!("{}", x);
    }
}

fn read_numbers(n: usize) -> Vec<usize> {
    (0..n).map(|_| read!()).collect()
}

// n: length of arr
// k: number of distinct values in arr
// T: O(n)
//    Sorting arr before calling this function is O(n log n)
// S: O(k), but O(n) in the worst case extra space
//    Sorting arr before calling this function is O(n) extra space
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
