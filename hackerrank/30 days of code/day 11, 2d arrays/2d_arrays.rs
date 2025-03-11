// https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true

use std::cmp::max;
use text_io::read;

const N_ROWS_COLUMNS: usize = 6;

fn main() {
    let matrix = read_matrix();
    println!("{}", calculate_max_sum(matrix));
}

fn read_matrix() -> [[i32; N_ROWS_COLUMNS]; N_ROWS_COLUMNS] {
    let mut matrix = [[0i32; N_ROWS_COLUMNS]; N_ROWS_COLUMNS];

    for row in matrix.iter_mut() {
        for element in row.iter_mut() {
            *element = read!();
        }
    }

    matrix
}

fn calculate_max_sum(matrix: [[i32; N_ROWS_COLUMNS]; N_ROWS_COLUMNS]) -> i32 {
    let mut max_sum = i32::MIN;
    const BEFORE_ROWS_COLUMNS_LIMIT: usize = 5;

    for i in 1..BEFORE_ROWS_COLUMNS_LIMIT {
        for j in 1..BEFORE_ROWS_COLUMNS_LIMIT {
            max_sum = max(max_sum, sum_around(matrix, i, j));
        }
    }

    max_sum
}

fn sum_around(matrix: [[i32; N_ROWS_COLUMNS]; N_ROWS_COLUMNS], i: usize, j: usize) -> i32 {
    matrix[i - 1][j - 1]
        + matrix[i - 1][j]
        + matrix[i - 1][j + 1]
        + matrix[i][j]
        + matrix[i + 1][j - 1]
        + matrix[i + 1][j]
        + matrix[i + 1][j + 1]
}
