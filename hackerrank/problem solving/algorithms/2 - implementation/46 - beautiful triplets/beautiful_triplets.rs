// Source: https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

use std::io::{stdin, BufRead};

fn main() {
    let _size: u32 = read!();
    let beautiful_difference: u32 = read!();
    let array: Vec<u32> = read_an_array();

    let n_beautiful_triplets: u32 = find_beautiful_triplets(array, beautiful_difference);
    println!("{}", n_beautiful_triplets);
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

fn find_beautiful_triplets(array: Vec<u32>, beautiful_difference: u32) -> u32 {
    let mut n_beautiful_triplets: u32 = 0;

    if array.len() > 2 {
        for i in 0..(array.len() - 2) {
            for j in (i + 1)..(array.len() - 1) {
                let first_difference: u32 = array[j] - array[i];

                if first_difference < beautiful_difference {
                    continue;
                } else if first_difference > beautiful_difference {
                    break;
                }

                for k in (j + 1)..array.len() {
                    let second_difference: u32 = array[k] - array[j];

                    if second_difference == beautiful_difference {
                        n_beautiful_triplets += 1;
                    } else if second_difference > beautiful_difference {
                        break;
                    }
                }
            }
        }
    }

    return n_beautiful_triplets;
}
