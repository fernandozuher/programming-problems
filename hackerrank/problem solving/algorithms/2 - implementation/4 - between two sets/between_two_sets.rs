// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

use num::integer::{gcd, lcm};

fn main() {
    let n1: usize = text_io::read!();
    let n2: usize = text_io::read!();
    let a: Vec<i32> = read_nums(n1);
    let b: Vec<i32> = read_nums(n2);
    println!("{}", between_two_sets(&a, &b));
}

fn read_nums(n: usize) -> Vec<i32> {
    (0..n).map(|_| text_io::read!()).collect()
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
