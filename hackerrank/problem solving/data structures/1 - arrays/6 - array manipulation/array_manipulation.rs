// https://www.hackerrank.com/challenges/crush/problem?is_full_screen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let n_queries: usize = read!();
    println!("{}", array_manipulation(n, n_queries));
}

// T: O(n + n_queries)
// S: O(n) extra space
fn array_manipulation(n: usize, n_queries: usize) -> i64 {
    let arr: Vec<i64> = populate_arr(n, n_queries);
    max_sequential_sum(&arr)
}

fn populate_arr(n: usize, n_queries: usize) -> Vec<i64> {
    // +2 = 1-indexed array + range-end
    let mut arr: Vec<i64> = vec![0; n + 2];

    for _i in 0..n_queries {
        let (b, e, summand): (usize, usize, i64) = (read!(), read!(), read!());
        arr[b] += summand;
        arr[e + 1] -= summand;
    }

    arr
}

fn max_sequential_sum(arr: &[i64]) -> i64 {
    arr.iter()
        .scan(0, |acc, &x| {
            *acc += x;
            Some(*acc)
        })
        .max()
        .unwrap_or(0)
}
