// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let n_rotation: usize = read!();
    let n_queries: usize = read!();
    let arr: Vec<i32> = read_numbers(n);
    let queries: Vec<i32> = read_numbers(n_queries);
    print_queries(&arr, &queries, n_rotation);
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn print_queries(arr: &[i32], queries: &[i32], n_rotation: usize) {
    let n = arr.len();
    let r = n_rotation % n;
    for &q in queries {
        let idx = (q as usize + n - r) % n;
        println!("{}", arr[idx]);
    }
}
