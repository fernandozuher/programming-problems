use std::env;
use std::fs::File;
use std::io::{self, BufRead, Write};

/*
 * Complete the 'diagonal_difference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

fn diagonal_difference(arr: &[Vec<i32>]) -> i32 {
    let (mut primary_diagonal, mut secondary_diagonal) = (0, 0);
    let early_indexes = 0..arr.len();
    let late_indexes = (0..arr.len()).rev();

    for (i, j) in early_indexes.zip(late_indexes) {
        primary_diagonal += arr[j][j];
        secondary_diagonal += arr[j][i];
    }
    let result = (primary_diagonal - secondary_diagonal).abs();
    return result;
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let mut fptr = File::create(env::var("OUTPUT_PATH").unwrap()).unwrap();
    let n = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();
    let mut arr: Vec<Vec<i32>> = Vec::with_capacity(n as usize);

    for i in 0..n as usize {
        arr.push(Vec::with_capacity(n as usize));

        arr[i] = stdin_iterator.next().unwrap().unwrap()
            .trim_end()
            .split(' ')
            .map(|s| s.to_string().parse::<i32>().unwrap())
            .collect();
    }

    let result = diagonal_difference(&arr);
    writeln!(&mut fptr, "{}", result).ok();
}
