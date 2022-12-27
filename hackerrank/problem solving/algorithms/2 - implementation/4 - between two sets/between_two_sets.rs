// Source: https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

use std::io::{self, BufRead};

/*
 * Complete the 'get_total_x' fntion below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

fn main() {    
    read_line_as_vec_i32();
    let set_a = read_line_as_vec_i32();
    let set_b = read_line_as_vec_i32();

    let total = get_total_x(&set_a, &set_b);
    println!("{}", total);
}

    fn read_line_as_vec_i32() -> Vec<i32> {
        let stdin = io::stdin();
        
        let numbers: Vec<i32> = stdin.lock()
          .lines().next().unwrap().unwrap()
          .trim().split(' ')
          .map(|s| s.parse().unwrap())
          .collect();

        return numbers;
    }

    fn get_total_x(set_a: &Vec<i32>, set_b: &Vec<i32>) -> i32 {
        let mut potential_factors = Vec::new();

        find_numbers_divisible_by_set_a(&mut potential_factors, set_a, set_b[0]);
        find_factors_of_set_b(&mut potential_factors, set_b);
        let total_factors = count_factors(potential_factors);

        return total_factors;
    }

        fn find_numbers_divisible_by_set_a(potential_factors: &mut Vec<i32>, set_a: &Vec<i32>, firstElementOfSetB: i32) {
            let last_element_set_a = set_a[set_a.len() - 1];

            for potential_factor in (last_element_set_a..(firstElementOfSetB + 1)).step_by(last_element_set_a as usize) {
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

        fn count_factors(potential_factors: Vec<i32>) -> i32 {
            let closure = |previousResult, item| -> i32 { 
                if item != 0 {previousResult + 1} else {previousResult}
            };
            let n_factors = potential_factors.into_iter().fold(0, closure);
            return n_factors;
        }