// https://www.hackerrank.com/challenges/crush/problem?is_full_screen=true

use std::cmp;
use text_io::read;

fn main() {
    let n: usize = read!();
    let n_queries: usize = read!();
    println!("{}", array_manipulation(n, n_queries));
}

fn array_manipulation(n: usize, n_queries: usize) -> i64 {
    // n + 2 = 1-indexed array + range-end
    let mut array: Vec<i64> = vec![0; n + 2];

    for _i in 0..n_queries {
        let (b, e, summand): (usize, usize, i64) = (read!(), read!(), read!());
        array[b] += summand;
        array[e + 1] -= summand;
    }

    let mut sum: i64 = 0;
    let mut max: i64 = 0;
    for x in array.iter() {
        if *x == 0 {
            continue;
        }
        sum += *x as i64;
        max = cmp::max(max, sum);
    }

    return max;
}
