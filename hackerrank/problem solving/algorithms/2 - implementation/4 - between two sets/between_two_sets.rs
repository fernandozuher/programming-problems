// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

use num_integer::{gcd, lcm};
use text_io::read;

fn main() {
    let n1: usize = read!();
    let n2: usize = read!();
    let numbers1: Vec<i32> = read_numbers(n1);
    let numbers2: Vec<i32> = read_numbers(n2);

    let lcm_of_numbers1: i32 = lcm_array(&numbers1);
    let gcd_of_numbers2: i32 = gcd_array(&numbers2);

    let count = (lcm_of_numbers1..=gcd_of_numbers2)
        .step_by(lcm_of_numbers1 as usize)
        .filter(|i| gcd_of_numbers2 % i == 0)
        .count();
    println!("{}", count);
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn lcm_array(numbers: &[i32]) -> i32 {
    numbers.iter().skip(1).fold(numbers[0], |a, &b| lcm(a, b))
}

fn gcd_array(numbers: &[i32]) -> i32 {
    numbers.iter().skip(1).fold(numbers[0], |a, &b| gcd(a, b))
}
