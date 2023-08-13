// https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

const n_rows_columns: usize = 6;

fn main() {
    let matrix = read_matrix();
    let max_sum: i32 = calculate_max_sum(matrix);
    println!("{}", max_sum);
}

fn read_matrix() -> [[i32; n_rows_columns]; n_rows_columns] {
    let mut matrix = [[0i32; n_rows_columns]; n_rows_columns];

    for row in matrix.iter_mut() {
        for element in row.iter_mut() {
            scan!("{}", *element);
        }
    }

    return matrix;
}

fn calculate_max_sum(matrix: [[i32; n_rows_columns]; n_rows_columns]) -> i32 {
    let mut max_sum: i32 = i32::MIN;
    const before_rows_columns_limit: usize = 5;

    for i in 1..before_rows_columns_limit {
        for j in 1..before_rows_columns_limit {
            max_sum = std::cmp::max(max_sum, sum_around(matrix, i, j));
        }
    }

    return max_sum;
}

fn sum_around(matrix: [[i32; n_rows_columns]; n_rows_columns], i: usize, j: usize) -> i32 {
    return matrix[i - 1][j - 1]
        + matrix[i - 1][j]
        + matrix[i - 1][j + 1]
        + matrix[i][j]
        + matrix[i + 1][j - 1]
        + matrix[i + 1][j]
        + matrix[i + 1][j + 1];
}
