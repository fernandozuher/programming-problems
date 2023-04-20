// Source: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

use std::io::{stdin, BufRead};

#[macro_use]
extern crate text_io;

fn main() {
    let _: i32 = read!();
    let cloud_array: Vec<i32> = read_an_array();
    let minimum_number_of_jumps: i32 = calculate_minimum_number_of_jumps(cloud_array);
    println!("{}", minimum_number_of_jumps);
}

fn read_an_array() -> Vec<i32> {
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

fn calculate_minimum_number_of_jumps(array: Vec<i32>) -> i32 {
    let mut i: usize = 0;
    let mut jumps: i32 = 0;
    let size: usize = array.len() - 1;

    while i < size {
        i = get_index_of_next_jump(i, array.clone());
        jumps += 1;
    }

    return jumps;
}

fn get_index_of_next_jump(mut index: usize, array: Vec<i32>) -> usize {
    if is_next_second_index_inside_range(index + 2, array.len()) {
        index += if is_next_second_cloud_cumulus(*array.get(index + 2).unwrap()) {
            2
        } else {
            1
        };
    } else {
        index += 1;
    }
    return index;
}

fn is_next_second_index_inside_range(index: usize, size: usize) -> bool {
    return index < size;
}

fn is_next_second_cloud_cumulus(type_of_cloud: i32) -> bool {
    return type_of_cloud == 0;
}
