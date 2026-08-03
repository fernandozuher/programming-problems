// https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

fn main() {
    let n: usize = text_io::read!();
    let arr: Vec<usize> = read_nums(n);
    for x in sequence_equation(&arr) {
        println!("{}", x)
    }
}

fn read_nums(n: usize) -> Vec<usize> {
    (0..n).map(|_| text_io::read!()).collect()
}

// n: length of arr/output
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
