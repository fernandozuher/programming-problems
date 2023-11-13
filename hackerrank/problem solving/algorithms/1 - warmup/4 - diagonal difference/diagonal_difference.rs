// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

use std::io::{stdin, BufRead};
use text_io::read;

fn main() {
    let n: usize = read!();
    let matrix: Vec<Vec<i32>> = read_matrix(n);
    println!("{}", diagonal_difference(&matrix));
}

fn read_matrix(n: usize) -> Vec<Vec<i32>> {
    let mut matrix: Vec<Vec<i32>> = vec![Vec::new(); n];

    for i in 0..n {
        matrix[i] = stdin()
            .lock()
            .lines()
            .next()
            .unwrap()
            .unwrap()
            .trim()
            .split(' ')
            .map(|s| s.parse().unwrap())
            .collect();
    }

    return matrix;
}

fn diagonal_difference(matrix: &Vec<Vec<i32>>) -> i32 {
    let (mut primary_diagonal, mut secondary_diagonal) = (0, 0);
    let early_indexes = 0..matrix.len();
    let late_indexes = (0..matrix.len()).rev();

    for (i, j) in early_indexes.zip(late_indexes) {
        primary_diagonal += matrix[j][j];
        secondary_diagonal += matrix[j][i];
    }

    return (primary_diagonal - secondary_diagonal).abs();
}
