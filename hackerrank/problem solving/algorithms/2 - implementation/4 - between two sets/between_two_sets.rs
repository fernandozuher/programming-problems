// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n1: usize = read!();
    let n2: usize = read!();
    let set_a: Vec<i32> = read_int_array(n1);
    let set_b: Vec<i32> = read_int_array(n2);
    println!("{}", find_total_factors(&set_a, &set_b));
}

    fn read_int_array(n: usize) -> Vec<i32> {
        return (0..n).map(|_| read!()).collect();
    }

    fn find_total_factors(set_a: &[i32], set_b: &[i32]) -> i32 {
        let mut potential_factors = vec![];
        find_numbers_divisible_by_set_a(&mut potential_factors, set_a, set_b[0]);
        find_factors_of_set_b(&mut potential_factors, set_b);
        return count_factors(&potential_factors);
    }

        fn find_numbers_divisible_by_set_a(potential_factors: &mut Vec<i32>, set_a: &[i32],
                                           first_element_of_set_b: i32) {
            let last_element_set_a = *set_a.last().unwrap();
            let range = last_element_set_a..(first_element_of_set_b + 1);

            for potential_factor in range.step_by(last_element_set_a as usize) {
                let mut is_a_real_potential_factor = true;

                for x in set_a {
                    if potential_factor % x != 0 {
                        is_a_real_potential_factor = false;
                        break;
                    }
                }

                if is_a_real_potential_factor {
                    potential_factors.push(potential_factor)
                }
            }
        }

        fn find_factors_of_set_b(potential_factors: &mut [i32], set_b: &[i32]) {
            for x in set_b {
                for potential_factor in potential_factors.iter_mut() {
                    if *potential_factor != 0 && (x % *potential_factor) != 0 {
                        *potential_factor = 0;
                    }
                }
            }
        }

        fn count_factors(potential_factors: &[i32]) -> i32 {
            let closure = |sum: i32, item: &i32| -> i32 {
                if *item != 0 {
                    sum + 1
                } else {
                    sum
                }
            };
            return potential_factors.iter().fold(0, closure);
        }
