// Source: https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

#[macro_use]
extern crate text_io;

use std::io::{stdin, BufRead};

fn main() {
    let _n_subjects: i32 = read!();
    let mut n_loaves_of_each_person: Vec<i32> = read_an_int_array();
    println!(
        "{}",
        find_min_loaves_to_satisfy_rules(&mut n_loaves_of_each_person)
    );
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

fn find_min_loaves_to_satisfy_rules(n_loaves_of_each_person: &mut Vec<i32>) -> String {
    let mut min_loaves_to_satisfy_rules: i32 = 0;

    for i in 0..(n_loaves_of_each_person.len() - 1) {
        if *n_loaves_of_each_person.get(i).unwrap() % 2 == 1 {
            n_loaves_of_each_person[i] += 1;
            n_loaves_of_each_person[i + 1] += 1;
            min_loaves_to_satisfy_rules += 2;
        }
    }

    return if (*n_loaves_of_each_person.last().unwrap()) % 2 == 1 {
        "NO".to_string()
    } else {
        min_loaves_to_satisfy_rules.to_string()
    };
}
