// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let test_cases: Vec<i32> = read_lines(n);
    print_array(utopian_tree(&test_cases));
}

fn read_lines(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn utopian_tree(test_cases: &Vec<i32>) -> Vec<i32> {
    let mut trees_heights: Vec<i32> = vec![0; test_cases.len()];
    for (i, height) in trees_heights.iter_mut().enumerate() {
        *height = calculate_height(test_cases[i]);
    }
    return trees_heights;
}

fn calculate_height(cycles: i32) -> i32 {
    let mut height = 1;
    for cycle in 1..=cycles {
        height = if is_cycle_happening_during_spring(cycle) {
            height * 2
        } else {
            height + 1
        };
    }
    return height;
}

fn is_cycle_happening_during_spring(cycle: i32) -> bool {
    return cycle & 1 == 1;
}

fn print_array(array: Vec<i32>) {
    for x in array.iter() {
        println!("{}", x);
    }
}
