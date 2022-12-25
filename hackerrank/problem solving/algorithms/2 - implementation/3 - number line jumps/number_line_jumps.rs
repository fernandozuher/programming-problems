// Source: https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

use std::env;
use std::fs::File;
use std::io::{self, BufRead, Write};

/*
 * Complete the 'kangaroo' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER v1
 *  3. INTEGER x2
 *  4. INTEGER v2
 */

fn kangaroo(x1: i32, v1: i32, x2: i32, v2: i32) -> String {
    if v2 >= v1 {
        return "NO".to_string();
    }

    let mut x1_mut = x1;
    let mut x2_mut = x2;

    while x1_mut < x2_mut {
        x1_mut += v1;
        x2_mut += v2;
    }

    if x1_mut == x2_mut {
        return "YES".to_string();
    } else {
        return "NO".to_string();
    }
}

fn read_input_as_i32_vec() -> Vec<i32> {
    let stdin = io::stdin();

    let numbers: Vec<i32> = stdin.lock()
          .lines().next().unwrap().unwrap()
          .trim().split(' ')
          .map(|s| s.parse().unwrap())
          .collect();

    return numbers;
}

fn main() {
    let mut fptr = File::create(env::var("OUTPUT_PATH").unwrap()).unwrap();

    let numbers = read_input_as_i32_vec();
    let x1 = numbers[0];
    let v1 = numbers[1];
    let x2 = numbers[2];
    let v2 = numbers[3];

    let result = kangaroo(x1, v1, x2, v2);
    writeln!(&mut fptr, "{}", result).ok();
}
