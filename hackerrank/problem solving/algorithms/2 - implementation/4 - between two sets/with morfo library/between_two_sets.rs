// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

use morfo::{read_ln, skip_input_ln};
use num::integer::{gcd, lcm};

fn main() {
    skip_input_ln();
    let a: Vec<i32> = read_ln();
    let b: Vec<i32> = read_ln();
    println!("{}", between_two_sets(&a, &b));
}

// n1, n2: length of a, b
// k: number of multiples tested = gcd_of_b / lcm_of_a
// T: O(n1 + n2 + k)
// S: O(1) extra space
fn between_two_sets(a: &[i32], b: &[i32]) -> usize {
    let lcm_of_a = reduce(a, lcm) as usize;
    let gcd_of_b = reduce(b, gcd) as usize;
    (lcm_of_a..=gcd_of_b)
        .step_by(lcm_of_a)
        .filter(|i| gcd_of_b % i == 0)
        .count()
}

fn reduce(arr: &[i32], func: fn(i32, i32) -> i32) -> i32 {
    arr.iter().copied().reduce(func).unwrap()
}
