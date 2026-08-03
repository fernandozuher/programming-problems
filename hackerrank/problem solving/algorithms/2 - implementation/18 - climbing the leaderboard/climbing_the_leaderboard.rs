// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

fn main() {
    let mut n: usize = text_io::read!();
    let mut ranked: Vec<i32> = read_nums(n);
    ranked.dedup();

    n = text_io::read!();
    let player: Vec<i32> = read_nums(n);

    for x in climbing_leaderboard(&ranked, &player) {
        println!("{}", x);
    }
}

fn read_nums(n: usize) -> Vec<i32> {
    (0..n).map(|_| text_io::read!()).collect()
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
