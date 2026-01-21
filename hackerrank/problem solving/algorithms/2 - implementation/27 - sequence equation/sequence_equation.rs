// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let arr: Vec<usize> = read_numbers(n);
    for x in sequence_equation(&arr) {
        println!("{}", x)
    }
}

fn read_numbers(n: usize) -> Vec<usize> {
    (0..n).map(|_| read!()).collect()
}

// n: length of array arr/output
// T: O(n)
// S: O(n) extra space
fn sequence_equation(arr: &[usize]) -> Vec<usize> {
    let mut values_to_index = vec![0; arr.len()];
    for (i, val) in arr.iter().enumerate() {
        values_to_index[val - 1] = i;
    }
    values_to_index
        .iter()
        .map(|&val| values_to_index[val] + 1)
        .collect()
}
