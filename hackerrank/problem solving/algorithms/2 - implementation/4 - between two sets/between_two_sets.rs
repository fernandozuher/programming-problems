// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

use num::integer::{gcd, lcm};
use text_io::read;

fn main() {
    let n1: usize = read!();
    let n2: usize = read!();
    let a: Vec<i32> = read_numbers(n1);
    let b: Vec<i32> = read_numbers(n2);
    println!("{}", between_two_sets(&a, &b));
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn between_two_sets(a: &[i32], b: &[i32]) -> usize {
    let lcm_of_a: i32 = lcm_array(&a);
    let gcd_of_b: i32 = gcd_array(&b);
    (lcm_of_a..=gcd_of_b)
        .step_by(lcm_of_a as usize)
        .filter(|i| gcd_of_b % i == 0)
        .count()
}

fn lcm_array(arr: &[i32]) -> i32 {
    arr.iter().copied().reduce(lcm).unwrap()
}

fn gcd_array(arr: &[i32]) -> i32 {
    arr.iter().copied().reduce(gcd).unwrap()
}
