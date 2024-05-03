// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

use std::cmp;
use std::collections::HashMap;
use std::io::{stdin, BufRead};

const NO_INDEX: i32 = -1;

fn main() {
    let _: i32 = read!();
    let array: Vec<i32> = read_an_int_array();
    println!("{}", find_minimum_distance(array));
}

fn read_an_int_array() -> Vec<i32> {
    let array: Vec<i32> = stdin()
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

fn find_minimum_distance(array: Vec<i32>) -> i32 {
    let mut minimum_distance: i32 = i32::MAX;
    let mut first_indexes_of_elements: HashMap<i32, (i32, i32)> = HashMap::new();

    for (i, element) in array.iter().enumerate() {
        if first_indexes_of_elements.contains_key(element) {
            let (mut first_index, mut second_index): (i32, i32) =
                *first_indexes_of_elements.get_mut(element).unwrap();

            if second_index == NO_INDEX {
                second_index = i as i32;
                first_indexes_of_elements.insert(*element, (first_index, second_index));
                let minimum_distance_of_current_element: i32 = second_index - first_index;
                minimum_distance = cmp::min(minimum_distance, minimum_distance_of_current_element);
            }
        } else {
            first_indexes_of_elements.insert(*element, (i as i32, NO_INDEX));
        }
    }

    return minimum_distance_or_no_index(minimum_distance);
}

fn minimum_distance_or_no_index(minimum_distance: i32) -> i32 {
    if minimum_distance != i32::MAX {
        return minimum_distance;
    } else {
        return NO_INDEX;
    };
}
