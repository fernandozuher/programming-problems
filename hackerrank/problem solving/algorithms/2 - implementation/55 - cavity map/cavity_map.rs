// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut matrix: Vec<Vec<char>> = read_matrix(n);
    change_matrix_to_cavity_map(&mut matrix);
    for x in matrix.iter() {
        println!("{}", x.iter().collect::<String>());
    }
}

fn read_matrix(n: usize) -> Vec<Vec<char>> {
    (0..n)
        .map(|_| {
            let x: String = read!();
            x.chars().collect::<Vec<char>>()
        })
        .collect()
}

// n: length of rows/cols of matrix
// T: O(n^2)
// S: O(1) extra space
fn change_matrix_to_cavity_map(matrix: &mut [Vec<char>]) {
    let range = 1..(matrix.len() - 1);
    for i in range.clone() {
        for j in range.clone() {
            if is_cell_cavity(matrix, i, j) {
                matrix[i][j] = 'X';
            }
        }
    }
}

fn is_cell_cavity(matrix: &[Vec<char>], i: usize, j: usize) -> bool {
    let c: char = matrix[i][j];
    matrix[i - 1][j] < c &&
        matrix[i][j - 1] < c &&
        matrix[i + 1][j] < c &&
        matrix[i][j + 1] < c
}
