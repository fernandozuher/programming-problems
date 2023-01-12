// Source: https://www.hackerrank.com/challenges/picking-numbers/problem?isFullScreen=true

use std::io::{self, BufRead};
use std::cmp;


fn main() {
    read_line_as_vec_i32();

    let mut numbers: Vec<i32> = read_line_as_vec_i32();
    numbers.sort();

    let result: usize = picking_numbers(&numbers);

    println!("{}", result);
}

    fn read_line_as_vec_i32() -> Vec<i32> {
        let stdin = io::stdin();

        let input_line: Vec<i32> = stdin.lock()
          .lines().next().unwrap().unwrap()
          .trim().split(' ')
          .map(|s| s.parse().unwrap())
          .collect();

        return input_line;
    }

    fn picking_numbers(numbers: &Vec<i32>) -> usize {
        let mut subarray_biggest_size: usize = 0;
        let mut first_reference_number_index: usize = 0;
        let mut second_reference_number_index: usize = 0;
        let mut subarray_current_size: usize = 1;

        for i in 1..numbers.len() {
            let difference: i32 = numbers[i] - numbers[first_reference_number_index];

            match difference {
                0 => subarray_current_size += 1,
                1 => {
                    subarray_current_size += 1;
                    if numbers[second_reference_number_index] != numbers[i] {
                        second_reference_number_index = i;
                    }
                }
                _ => {
                    subarray_biggest_size = update_longest_subarray_size(subarray_biggest_size, subarray_current_size);

                    let update: Vec<usize> = update_first_reference_number_index_and_subarray_current_size(numbers, i, second_reference_number_index);

                    first_reference_number_index = *update.first().unwrap();
                    second_reference_number_index = i;
                    subarray_current_size = *update.last().unwrap();
                }
            }
        }

        subarray_biggest_size = update_longest_subarray_size(subarray_biggest_size, subarray_current_size);
        return subarray_biggest_size;
    }

        fn update_longest_subarray_size(subarray_biggest_size: usize, subarray_current_size: usize) -> usize {
            return cmp::max(subarray_biggest_size, subarray_current_size);
        }

        fn update_first_reference_number_index_and_subarray_current_size(numbers: &Vec<i32>, i: usize, second_reference_number_index: usize) -> Vec<usize> {
            let (first_reference_number_index, subarray_current_size): (usize, usize);

            if numbers[i] - numbers[second_reference_number_index] == 1 {
                first_reference_number_index = second_reference_number_index;
                subarray_current_size = i - second_reference_number_index + 1;
            }
            else {
                first_reference_number_index = i;
                subarray_current_size = 1;
            }

            let result = vec![first_reference_number_index, subarray_current_size];
            return result;
        }
