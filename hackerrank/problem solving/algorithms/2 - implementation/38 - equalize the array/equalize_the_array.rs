// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

use counter_fpy::Counter;
use text_io::read;

fn main() {
    let n: usize = read!();
    println!("{}", equalize_array(read_numbers(n)));
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn equalize_array(arr: Vec<i32>) -> usize {
    let collection = Counter::from(Counter::new(), arr.clone());
    let max_count = collection
        .iter()
        .max_by_key(|(_k, v)| *v)
        .unwrap_or((&0, &0))
        .1;
    arr.len() - max_count
}
