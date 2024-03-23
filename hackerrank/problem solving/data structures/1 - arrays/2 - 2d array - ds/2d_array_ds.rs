// https://www.hackerrank.com/challenges/2d-array/problem?isFullScreen=true

use std::cmp;
use text_io::read;

fn main() {
    const n: usize = 6;
    let mut matrix: Vec<Vec<i32>> = vec![vec![0; n]; n];
    for row in matrix.iter_mut() {
        row.fill_with(|| read!());
    }
    println!("{}", max_hourglass_sum(&matrix));
}

fn max_hourglass_sum(matrix: &Vec<Vec<i32>>) -> i32 {
    let mut max_sum: i32 = i32::MIN;
    const rows_cols: usize = 4;

    for i in 1..=rows_cols {
        for j in 1..=rows_cols {
            let current_sum: i32 = hourglass_sum(matrix, i, j);
            max_sum = cmp::max(max_sum, current_sum);
        }
    }

    return max_sum;
}

fn hourglass_sum(matrix: &Vec<Vec<i32>>, i: usize, j: usize) -> i32 {
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

    return subrow1_sum + matrix[i][j] + subrow3_sum;
}
