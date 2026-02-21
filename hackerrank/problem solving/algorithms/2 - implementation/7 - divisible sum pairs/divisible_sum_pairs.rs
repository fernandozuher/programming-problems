// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

use num::Integer;
use text_io::read;

fn main() {
    let (n, k): (usize, usize) = (read!(), read!());
    let numbers: Vec<usize> = read_numbers(n);
    println!("{}", divisible_sum_pairs(&numbers, k));
}

fn read_numbers(n: usize) -> Vec<usize> {
    (0..n).map(|_| read!()).collect()
}

// n: length of array numbers
// k: length of array frequency
// T: O(n + k)
// S: O(k) extra space
fn divisible_sum_pairs(numbers: &[usize], k: usize) -> usize {
    let frequency: Vec<usize> = init_remainder_frequency(numbers, k);
    count_pairs_with_remainder_0(&frequency)
        + count_complementary_remainder_pairs(&frequency)
        + count_pairs_with_remainder_k_half(&frequency)
}

fn init_remainder_frequency(numbers: &[usize], k: usize) -> Vec<usize> {
    let mut frequency: Vec<usize> = vec![0; k];
    for &x in numbers.iter() {
        frequency[x % k] += 1;
    }
    frequency
}

fn count_pairs_with_remainder_0(frequency: &[usize]) -> usize {
    pair_count(frequency[0])
}

fn pair_count(n: usize) -> usize {
    n * (n - 1) / 2
}

fn count_complementary_remainder_pairs(frequency: &[usize]) -> usize {
    let n: usize = frequency.len();
    (1..(n + 1) / 2)
        .map(|i| frequency[i] * frequency[n - i])
        .sum()
}

fn count_pairs_with_remainder_k_half(frequency: &[usize]) -> usize {
    let n: usize = frequency.len();
    if n.is_even() {
        return pair_count(frequency[n / 2]);
    }
    0
}
