// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

use morfo::{println, read_ln, skip_input_ln};

fn main() {
    skip_input_ln();
    let mut ranked: Vec<i32> = read_ln();
    ranked.dedup();

    skip_input_ln();
    let player: Vec<i32> = read_ln();

    println(&climbing_leaderboard(&ranked, &player));
}

// n1: length of player, output
// n2: length of ranked
// T: O(n1 + n2)
// S: O(n1) extra space
fn climbing_leaderboard(ranked: &[i32], player: &[i32]) -> Vec<i32> {
    let mut i: i32 = ranked.len() as i32 - 1;
    player
        .iter()
        .map(|&score| {
            while i >= 0 && score >= ranked[i as usize] {
                i -= 1;
            }
            i + 2
        })
        .collect()
}
