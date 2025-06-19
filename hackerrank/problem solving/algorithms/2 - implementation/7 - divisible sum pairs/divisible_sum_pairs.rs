// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

use text_io::read;

fn main() {
    let (n, k): (usize, usize) = (read!(), read!());
    let numbers: Vec<usize> = read_numbers(n);
    println!("{}", divisible_sum_pairs(&numbers, k));
}

fn read_numbers(n: usize) -> Vec<usize> {
    (0..n).map(|_| read!()).collect()
}

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
    let k: usize = frequency.len();
    (1..(k + 1) / 2).fold(0, |acc, i| acc + frequency[i] * frequency[k - i])
}

fn count_pairs_with_remainder_k_half(frequency: &[usize]) -> usize {
    let k: usize = frequency.len();
    if k % 2 == 0 {
        pair_count(frequency[k / 2])
    } else {
        0
    }
}
