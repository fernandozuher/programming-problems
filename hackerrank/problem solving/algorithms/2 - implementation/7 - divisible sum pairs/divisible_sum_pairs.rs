// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

use text_io::read;

fn main() {
    let (mut n, mut k): (usize, i32) = (read!(), read!());
    let mut array = read_int_array(n);

    array.sort();

    println!("{}", divisible_sum_pairs(&array, k));
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn divisible_sum_pairs(array: &Vec<i32>, k: i32) -> i32 {
    let mut n_divisible_sum_pairs = 0;

    for i in 0..(array.len() - 1) {
        for j in (i + 1)..array.len() {
            if array[i] <= array[j] && ((array[i] + array[j]) % k == 0) {
                n_divisible_sum_pairs += 1;
            }
        }
    }

    return n_divisible_sum_pairs;
}
