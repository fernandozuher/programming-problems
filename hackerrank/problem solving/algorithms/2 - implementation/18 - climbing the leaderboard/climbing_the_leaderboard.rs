// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

use text_io::read;

fn main() {
    let mut n: usize = read!();
    let mut ranked: Vec<i32> = read_numbers(n);
    ranked.dedup();

    n = read!();
    let player: Vec<i32> = read_numbers(n);

    for x in climbing_leaderboard(&ranked, &player) {
        println!("{}", x);
    }
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

// n: length of array player and returned output array
// m: length of array ranked
// T: O(n + m)
// S: O(n) extra space
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
