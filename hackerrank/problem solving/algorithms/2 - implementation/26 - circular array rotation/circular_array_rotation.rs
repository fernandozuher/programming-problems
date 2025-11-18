// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let n_rotation: usize = read!();
    let n_queries: usize = read!();
    let arr: Vec<i32> = read_numbers(n);
    print_queries(&arr, n_rotation, n_queries);
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn print_queries(arr: &[i32], n_rotation: usize, n_queries: usize) {
    let n = arr.len();
    let r = n_rotation % n;
    for _ in 0..n_queries {
        let query: i32 = read!();
        let idx = (query as usize + n - r) % n;
        println!("{}", arr[idx]);
    }
}
