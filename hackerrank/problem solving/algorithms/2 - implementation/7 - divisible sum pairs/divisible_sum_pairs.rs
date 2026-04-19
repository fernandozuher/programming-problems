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

// n: length of numbers
// k: length of freq
// T: O(n + k)
// S: O(k) extra space
fn divisible_sum_pairs(numbers: &[usize], k: usize) -> usize {
    let freq: Vec<usize> = init_remainder_frequency(numbers, k);
    count_pairs_with_remainder_0(&freq)
        + count_complementary_remainder_pairs(&freq)
        + count_pairs_with_remainder_k_half(&freq)
}

fn init_remainder_frequency(numbers: &[usize], k: usize) -> Vec<usize> {
    let mut freq: Vec<usize> = vec![0; k];
    for &x in numbers.iter() {
        freq[x % k] += 1;
    }
    freq
}

fn count_pairs_with_remainder_0(freq: &[usize]) -> usize {
    pair_count(freq[0])
}

fn pair_count(n: usize) -> usize {
    n * (n - 1) / 2
}

fn count_complementary_remainder_pairs(freq: &[usize]) -> usize {
    let n: usize = freq.len();
    (1..(n + 1) / 2)
        .map(|i| freq[i] * freq[n - i])
        .sum()
}

fn count_pairs_with_remainder_k_half(freq: &[usize]) -> usize {
    let n: usize = freq.len();
    if n.is_even() {
        return pair_count(freq[n / 2]);
    }
    0
}
