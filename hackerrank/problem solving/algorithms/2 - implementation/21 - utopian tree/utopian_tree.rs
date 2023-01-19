// Source: https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

use std::io::{self, BufRead};


fn main() {
    let n_test_cases: i32 = read_line_as_i32();
    let n_test_cases_cycles: Vec<i32> = read_n_test_cases_cycles(n_test_cases);

    let trees_heights = utopian_tree(&n_test_cases_cycles);
    print_trees_heights(trees_heights);
}

    fn read_line_as_i32() -> i32 {
        let stdin = io::stdin();
        
        let mut input_line = String::new();
        stdin.read_line(&mut input_line).expect("Failed to read line");

        let number: i32 = input_line.trim().parse().expect("Input not an integer");

        return number;
    }

    fn read_n_test_cases_cycles(n_test_cases: i32) -> Vec<i32> {
        let mut n_test_cases_cycles: Vec<i32> = Vec::with_capacity(n_test_cases as usize);
        unsafe { n_test_cases_cycles.set_len(n_test_cases as usize); }

        n_test_cases_cycles.fill_with(read_line_as_i32);

        return n_test_cases_cycles;
    }

    fn utopian_tree(n_test_cases_cycles: &Vec<i32>) -> Vec<i32> {
        let mut tree_height: Vec<i32> = Vec::with_capacity(n_test_cases_cycles.len());
        unsafe { tree_height.set_len(n_test_cases_cycles.len()); }

        for (i, height) in tree_height.iter_mut().enumerate() {
            *height = calculate_height(n_test_cases_cycles[i]);
        }

        return tree_height;
    }

        fn calculate_height(cycles: i32) -> i32 {
            let mut height = 1;
            for cycle in 1..=cycles {
                height = if is_cycle_happening_during_spring(cycle) {height * 2} else {height + 1};
            }
            return height;
        }

            fn is_cycle_happening_during_spring(cycle: i32) -> bool {
                return cycle & 1 == 1;
            }

    fn print_trees_heights(trees_heights: Vec<i32>) {
        for height in trees_heights.iter() {
            println!("{}", height);
        }
    }
