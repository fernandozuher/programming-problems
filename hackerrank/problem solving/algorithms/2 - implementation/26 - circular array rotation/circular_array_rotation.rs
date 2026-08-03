// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

fn main() {
    let n: usize = text_io::read!();
    let n_rotation: usize = text_io::read!();
    let n_queries: usize = text_io::read!();
    let arr: Vec<i32> = read_nums(n);
    print_queries(&arr, n_rotation, n_queries);
}

fn read_nums(n: usize) -> Vec<i32> {
    (0..n).map(|_| text_io::read!()).collect()
}

// T: O(n_queries)
// S: O(1) extra space
fn print_queries(arr: &[i32], n_rotation: usize, n_queries: usize) {
    let n: usize = arr.len();
    let offset: usize = n - n_rotation % n;
    for _ in 0..n_queries {
        let query: usize = text_io::read!();
        let idx = (query + offset) % n;
        println!("{}", arr[idx]);
    }
}
