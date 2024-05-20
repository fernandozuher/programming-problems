// https://www.hackerrank.com/challenges/cavity-map/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n_rows_columns: usize = read!();
    let mut matrix: Vec<String> = Vec::new();
    matrix.resize_with(n_rows_columns, || read!());
    change_matrix_to_cavity_map(&mut matrix);
    matrix.iter().for_each(|x| println!("{}", x));
}

fn change_matrix_to_cavity_map(matrix: &mut [String]) {
    const CAVITY: &str = "X";
    for i in 1..(matrix.len() - 1) {
        for j in 1..(matrix.len() - 1) {
            if is_cell_cavity(matrix, i, j) {
                matrix[i].replace_range(j..j + 1, CAVITY);
            }
        }
    }
}

fn is_cell_cavity(matrix: &mut [String], i: usize, j: usize) -> bool {
    return matrix[i - 1].chars().nth(j) < matrix[i].chars().nth(j)
        && matrix[i].chars().nth(j - 1) < matrix[i].chars().nth(j)
        && matrix[i + 1].chars().nth(j) < matrix[i].chars().nth(j)
        && matrix[i].chars().nth(j + 1) < matrix[i].chars().nth(j);
}
