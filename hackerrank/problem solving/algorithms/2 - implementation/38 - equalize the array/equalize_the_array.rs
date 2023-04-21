// Source: https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

use std::cmp;
use std::io::{stdin, BufRead};

fn main() {
    let _size_array: u32 = read!();
    let array: Vec<u32> = read_an_array();

    let minimum_number_of_deletions_required: u32 = equalize_array(array);
    println!("{}", minimum_number_of_deletions_required);
}

fn read_an_array() -> Vec<u32> {
    let array: Vec<u32> = stdin()
        .lock()
        .lines()
        .next()
        .unwrap()
        .unwrap()
        .trim()
        .split(' ')
        .map(|s| s.parse().unwrap())
        .collect();
    return array;
}

fn equalize_array(mut array: Vec<u32>) -> u32 {
    array.sort();
    let maximum_quantity_of_equal_element: u32 =
        find_maximum_quantity_of_equal_element(array.clone());
    let minimum_number_of_deletions_required: u32 =
        array.len() as u32 - maximum_quantity_of_equal_element;
    return minimum_number_of_deletions_required;
}

fn find_maximum_quantity_of_equal_element(array: Vec<u32>) -> u32 {
    let mut maximum_quantity_of_equal_element: u32 = 1;
    let mut temporary_quantity_equal_element: u32 = 1;

    for i in 1..array.len() {
        if are_consecutive_elementes_equal(*array.get(i - 1).unwrap(), *array.get(i).unwrap()) {
            temporary_quantity_equal_element += 1;
            maximum_quantity_of_equal_element = cmp::max(
                temporary_quantity_equal_element,
                maximum_quantity_of_equal_element,
            );
        } else {
            temporary_quantity_equal_element = 1;
        }
    }

    return maximum_quantity_of_equal_element;
}

fn are_consecutive_elementes_equal(element_1: u32, element_2: u32) -> bool {
    return element_1 == element_2;
}
