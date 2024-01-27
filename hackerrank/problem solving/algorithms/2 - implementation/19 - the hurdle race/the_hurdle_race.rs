// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let maximum_height_can_jump: i32 = read!();
    let hurdle_heights = read_int_array(n);
    println!("{}", hurdle_race(&hurdle_heights, maximum_height_can_jump));
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn hurdle_race(hurdles_heights: &Vec<i32>, maximum_height_can_jump: i32) -> i32 {
    let highest_hurdle: i32 = *hurdles_heights.iter().max().unwrap();

    if highest_hurdle > maximum_height_can_jump {
        return highest_hurdle - maximum_height_can_jump;
    } else {
        return 0;
    };
}
