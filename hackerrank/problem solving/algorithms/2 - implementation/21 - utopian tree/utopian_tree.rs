// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    for x in 0..n {
        let cycles: i32 = read!();
        println!("{}", utopian_tree(cycles));
    }
}

fn utopian_tree(cycles: i32) -> i32 {
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
