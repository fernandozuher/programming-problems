// Source: https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

use std::io::{self, BufRead};
use std::cmp;


fn main() {
    let input_line: Vec<i32> = read_line_as_vec_i32();
    let maximum_height_can_jump: i32 = *input_line.last().unwrap();

    let hurdle_heights = read_line_as_vec_i32();

    let result = hurdle_race(&hurdle_heights, maximum_height_can_jump);
    println!("{}", result);
}

    fn read_line_as_vec_i32() -> Vec<i32> {
        let stdin = io::stdin();

        let input_line: Vec<i32> = stdin.lock()
          .lines().next().unwrap().unwrap()
          .trim().split(' ')
          .map(|s| s.parse().unwrap())
          .collect();

        return input_line;
    }

    fn hurdle_race(hurdles_heights: &Vec<i32>, maximum_height_can_jump: i32) -> i32 {
        let highest_hurdle: i32 = *hurdles_heights.iter().max().unwrap();
        let doses: i32 = if highest_hurdle > maximum_height_can_jump {highest_hurdle - maximum_height_can_jump} else {0};
        return doses;
    }
