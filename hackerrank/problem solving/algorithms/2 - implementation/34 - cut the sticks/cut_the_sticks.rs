// Source: https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

use std::io::{stdin, BufRead};

fn main() {
    let _size: usize = read!();
    let mut array: Vec<usize> = read_an_array();
    array.sort();

    let result: Vec<usize> = cut_the_sticks(array);
    print_array(result);
}

fn read_an_array() -> Vec<usize> {
    let array: Vec<usize> = stdin()
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

fn cut_the_sticks(mut array: Vec<usize>) -> Vec<usize> {
    let size: usize = array.len();
    let mut remaining_sticks_of_each_iteration: Vec<usize> = initialize_result(size);

    let mut i = 0;
    while i < size {
        let shortest_stick_length: usize = array[i];

        i = find_first_element_index_different_of_first_current_shortest_stick_length_index(
            i,
            array.clone(),
        );

        let current_iteration_size: usize = size - i;
        if i == size {
            break;
        }

        remaining_sticks_of_each_iteration.push(current_iteration_size);
        array = decrease_sticks_lengths_higher_than_current_shortest_stick_length(
            i,
            array.clone(),
            shortest_stick_length,
        );
    }

    return remaining_sticks_of_each_iteration;
}

fn initialize_result(size: usize) -> Vec<usize> {
    let mut remaining_sticks_of_each_iteration: Vec<usize> = Vec::new();
    remaining_sticks_of_each_iteration.push(size);
    return remaining_sticks_of_each_iteration;
}

fn find_first_element_index_different_of_first_current_shortest_stick_length_index(
    mut index: usize,
    array: Vec<usize>,
) -> usize {
    let size: usize = array.len();
    let shortest_stick_length: usize = array[index];

    while index < size && array[index] == shortest_stick_length {
        index += 1;
    }

    return index;
}

fn decrease_sticks_lengths_higher_than_current_shortest_stick_length(
    index: usize,
    mut array: Vec<usize>,
    shortest_stick_length: usize,
) -> Vec<usize> {
    for i in index..array.len() {
        array[i] -= shortest_stick_length;
    }
    return array;
}

fn print_array(array: Vec<usize>) {
    array.iter().for_each(|element| println!("{}", element));
}
