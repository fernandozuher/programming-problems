use std::env;
use std::fs::File;
use std::io::{self, BufRead, Write};

/*
 * Complete the 'compare_triplets' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

fn compare_triplets(a: &[i32], b: &[i32]) -> Vec<i32> {
    let (mut player1, mut player2) = (0, 0);

    for (number1, number2) in a.iter().zip(b.iter()) {
        if number1 > number2 {
            player1 += 1;
        }
        else if number2 > number1 {
            player2 += 1;
        }
    }
    return vec![player1, player2];
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let mut fptr = File::create(env::var("OUTPUT_PATH").unwrap()).unwrap();

    let a: Vec<i32> = stdin_iterator.next().unwrap().unwrap()
        .trim_end()
        .split(' ')
        .map(|s| s.to_string().parse::<i32>().unwrap())
        .collect();

    let b: Vec<i32> = stdin_iterator.next().unwrap().unwrap()
        .trim_end()
        .split(' ')
        .map(|s| s.to_string().parse::<i32>().unwrap())
        .collect();

    let result = compare_triplets(&a, &b);

    for i in 0..result.len() {
        write!(&mut fptr, "{}", result[i]).ok();

        if i != result.len() - 1 {
            write!(&mut fptr, " ").ok();
        }
    }

    writeln!(&mut fptr).ok();
}
