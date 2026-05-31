// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

use std::cmp;
use text_io::read;

fn main() {
    let matrix: Vec<Vec<i32>> = read_matrix();
    println!("{}", max_hourglass_sum(&matrix));
}

fn read_matrix() -> Vec<Vec<i32>> {
    const N: usize = 6;
    let matrix: Vec<Vec<i32>> = (0..N).map(|_| (0..N).map(|_| read!()).collect()).collect();
    matrix
}

// T: O(1)
// S: O(1) extra space
fn max_hourglass_sum(matrix: &[Vec<i32>]) -> i32 {
    let mut max_sum: i32 = i32::MIN;
    const ROWS_COLS: usize = 4;

    for i in 1..=ROWS_COLS {
        for j in 1..=ROWS_COLS {
            let current_sum: i32 = hourglass_sum(matrix, i, j);
            max_sum = cmp::max(max_sum, current_sum);
        }
    }

    max_sum
}

fn hourglass_sum(matrix: &[Vec<i32>], i: usize, j: usize) -> i32 {
    let subrow1_first_index: usize = i - 1;
    let subrow3_first_index: usize = i + 1;
    let first_col_index: usize = j - 1;
    let end: usize = first_col_index + 3;

    let subrow1_sum: i32 = matrix[subrow1_first_index][first_col_index..end]
        .iter()
        .sum();
    let subrow3_sum: i32 = matrix[subrow3_first_index][first_col_index..end]
        .iter()
        .sum();

    subrow1_sum + matrix[i][j] + subrow3_sum
}
