// Source: https://www.hackerrank.com/challenges/permutation-equation/problem?isFullScreen=true

use std::io::{stdin, BufRead};

#[macro_use]
extern crate text_io;


fn main() {
    let _: i32 = read!();
    let array: Vec<i32> = read_an_array();

    let permutated_array: Vec<i32> = permutation_equation(array);
    print_array(permutated_array);
}

    fn read_an_array() -> Vec<i32> {
        let array: Vec<i32> = stdin().lock()
                              .lines().next().unwrap().unwrap()
                              .trim().split(' ')
                              .map(|s| s.parse().unwrap())
                              .collect();
        return array;
    }

    fn permutation_equation(array: Vec<i32>) -> Vec<i32> {
        let array_elements_positions: Vec<i32> = generate_array_of_elements_positions(array);
        let permutated_array: Vec<i32> = generate_permutated_array(array_elements_positions);
        return permutated_array;
    }

        fn generate_array_of_elements_positions(array: Vec<i32>) -> Vec<i32> {
            let mut array_elements_positions: Vec<i32> = Vec::with_capacity(array.len());
            unsafe { array_elements_positions.set_len(array.len()); }

            for (i, element) in array.iter().enumerate() {
                array_elements_positions[*element as usize - 1] = i as i32;
            }

            return array_elements_positions;
        }

        fn generate_permutated_array(array: Vec<i32>) -> Vec<i32> {
            let mut permutated_array: Vec<i32> = Vec::with_capacity(array.len());
            unsafe { permutated_array.set_len(array.len()); }

            for (i, element) in array.iter().enumerate() {
                permutated_array[i] = array[*element as usize] + 1;
            }

            return permutated_array;
        }

    fn print_array(array: Vec<i32>) {
        for element in array {
            println!("{}", element);
        }
    }
