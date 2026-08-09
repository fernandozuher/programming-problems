// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

use morfo::{read, read_n};

fn main() {
    let n: usize = read();
    let n_rotation: usize = read();
    let n_queries: usize = read();
    let arr: Vec<i32> = read_n(n);
    print_queries(&arr, n_rotation, n_queries);
}

// T: O(n_queries)
// S: O(1) extra space
fn print_queries(arr: &[i32], n_rotation: usize, n_queries: usize) {
    let n: usize = arr.len();
    let offset: usize = n - n_rotation % n;
    for _ in 0..n_queries {
        let query: usize = read();
        let idx = (query + offset) % n;
        println!("{}", arr[idx]);
    }
}
