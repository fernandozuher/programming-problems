// Source: https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

use text_io::{read, scan};

fn main() {
    let (n1, n2): (usize, usize);
    scan!("{} {}", n1, n2);
    let set_a: Vec<i32> = read_int_array(n1);
    let set_b: Vec<i32> = read_int_array(n2);

    println!("{}", find_total_factors(&set_a, &set_b));
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn find_total_factors(set_a: &Vec<i32>, set_b: &Vec<i32>) -> i32 {
    let mut potential_factors = Vec::new();

    find_numbers_divisible_by_set_a(&mut potential_factors, set_a, set_b[0]);
    find_factors_of_set_b(&mut potential_factors, set_b);
    let total_factors = count_factors(&potential_factors);

    return total_factors;
}

fn find_numbers_divisible_by_set_a(
    potential_factors: &mut Vec<i32>,
    set_a: &Vec<i32>,
    firstElementOfSetB: i32,
) {
    let last_element_set_a = set_a[set_a.len() - 1];

    for potential_factor in
        (last_element_set_a..(firstElementOfSetB + 1)).step_by(last_element_set_a as usize)
    {
        let mut is_a_real_potential_factor = true;

        for number in set_a {
            if potential_factor % number != 0 {
                is_a_real_potential_factor = false;
                break;
            }
        }

        if is_a_real_potential_factor == true {
            potential_factors.push(potential_factor)
        }
    }
}

fn find_factors_of_set_b(potential_factors: &mut Vec<i32>, set_b: &Vec<i32>) {
    for number in set_b {
        for i in 0..potential_factors.len() {
            if potential_factors[i] != 0 && (number % potential_factors[i]) != 0 {
                potential_factors[i] = 0;
            }
        }
    }
}

fn count_factors(potential_factors: &Vec<i32>) -> i32 {
    let closure = |sum: i32, item: &i32| -> i32 {
        if *item != 0 {
            sum + 1
        } else {
            sum
        }
    };
    let n_factors = potential_factors.iter().fold(0, closure);
    return n_factors;
}
