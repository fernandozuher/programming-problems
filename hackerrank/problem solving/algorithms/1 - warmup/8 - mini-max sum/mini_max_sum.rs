// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

use text_io::read;

fn main() {
    const N: usize = 5;
    let mut array: Vec<i64> = read_int_array(N);
    array.sort();
    let (min, max) = mini_max_sum(&array);
    print!("{} {}", min, max);
}

fn read_int_array(n: usize) -> Vec<i64> {
    return (0..n).map(|_| read!()).collect();
}

fn mini_max_sum(array: &Vec<i64>) -> (i64, i64) {
    let mut sum: i64 = array.iter().sum();
    let min_sum: i64 = sum - array[array.len() - 1];
    let max_sum: i64 = sum - array[0];
    return (min_sum, max_sum);
}
