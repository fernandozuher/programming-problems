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
        let elements_positions_array: Vec<i32> = generate_elements_positions_array(array);
        let permutated_array: Vec<i32> = generate_permutated_array(elements_positions_array);
        return permutated_array;
    }

        fn generate_elements_positions_array(array: Vec<i32>) -> Vec<i32> {
            let mut elements_positions_array: Vec<i32> = Vec::with_capacity(array.len());
            unsafe { elements_positions_array.set_len(array.len()); }

            for (i, element) in array.iter().enumerate() {
                elements_positions_array[*element as usize - 1] = i as i32;
            }

            return elements_positions_array;
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
