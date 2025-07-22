// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

use text_io::read;

fn main() {
    let mut n: usize = read!();
    let mut ranked: Vec<i32> = read_numbers(n);
    ranked.dedup();

    n = read!();
    let player: Vec<i32> = read_numbers(n);

    climbing_leaderboard(&ranked, &player)
        .iter()
        .for_each(|x| println!("{}", x));
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn climbing_leaderboard(ranked: &[i32], player: &[i32]) -> Vec<i32> {
    let mut player_ranks: Vec<i32> = vec![0; player.len()];
    let mut i: i32 = ranked.len() as i32 - 1;

    for (j, &score) in player.iter().enumerate() {
        while i >= 0 && score >= ranked[i as usize] {
            i -= 1
        }
        player_ranks[j] = i + 2;
    }

    player_ranks
}
