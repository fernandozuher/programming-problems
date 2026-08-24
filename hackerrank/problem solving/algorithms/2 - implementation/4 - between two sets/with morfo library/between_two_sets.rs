// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

use morfo::{gcd, lcm, read_ln, skip_input_ln};

fn main() {
    skip_input_ln();
    // i64, not i32: the lcm of ten values under 100 reaches 3.1e15, which
    // overflows an i32 fold and panics in a debug build.
    let a: Vec<i64> = read_ln();
    let b: Vec<i64> = read_ln();
    println!("{}", between_two_sets(&a, &b));
}

// n1, n2: length of a, b
// k: number of multiples tested = gcd_of_b / lcm_of_a
// T: O(n1 + n2 + k)
// S: O(1) extra space
fn between_two_sets(a: &[i64], b: &[i64]) -> usize {
    let lcm_of_a = lcm(a.iter().copied()) as usize;
    let gcd_of_b = gcd(b.iter().copied()) as usize;
    (lcm_of_a..=gcd_of_b)
        .step_by(lcm_of_a)
        .filter(|i| gcd_of_b % i == 0)
        .count()
}
