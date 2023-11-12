// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

use std::io::{stdin, BufRead};

fn main() {
    let array1: Vec<i32> = read_and_int_array();
    let array2: Vec<i32> = read_and_int_array();
    let result: Vec<i32> = compare_triplets(&array1, &array2);
    println!("{} {}", result[0], result[1]);
}

fn read_and_int_array() -> Vec<i32> {
    return stdin()
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

fn compare_triplets(array1: &Vec<i32>, array2: &Vec<i32>) -> Vec<i32> {
    let (mut player1, mut player2) = (0, 0);

    for (val1, val2) in array1.iter().zip(array2.iter()) {
        if val1 > val2 {
            player1 += 1;
        } else if val2 > val1 {
            player2 += 1;
        }
    }

    return vec![player1, player2];
}
