// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let test_cases: Vec<i32> = read_numbers(n);
    for x in utopian_tree(&test_cases) {
        println!("{}", x);
    }
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn utopian_tree(test_cases: &[i32]) -> Vec<i32> {
    test_cases.iter().map(calculate_height).collect()
}

fn calculate_height(cycles: &i32) -> i32 {
    (1..cycles + 1).fold(1, |height, cycle| {
        if is_cycle_happening_during_spring(cycle) {
            height * 2
        } else {
            height + 1
        }
    })
}

fn is_cycle_happening_during_spring(cycle: i32) -> bool {
    cycle & 1 == 1
}
