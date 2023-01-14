// Source: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

use std::io::{self, BufRead};

fn main() {
    read_line_as_vec_i32();
    let mut ranked = read_line_as_vec_i32();
    
    read_line_as_vec_i32();
    let player = read_line_as_vec_i32();

    ranked.dedup();

    let result: Vec<i32> = climbing_leaderboard(&mut ranked, &player);
    print_result(result);
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

    fn climbing_leaderboard(ranked: &mut Vec<i32>, player: &Vec<i32>) -> Vec<i32> {
        let mut player_rank: Vec<i32> = Vec::with_capacity(player.len());
        unsafe { player_rank.set_len(player.len()); }

        for i in 0..player.len() {
            let last_index: i32 = (ranked.len() as i32) - 1;
            let mut index: i32 = binary_search_descending_order(ranked, 0, last_index, player[i]);
            player_rank[i] = index + 1;
        }

        return player_rank;
    }

        fn binary_search_descending_order(ranked: &Vec<i32>, low: i32, high: i32, key: i32) -> i32 {
            if high >= low {
               let middle: usize = (low + ((high - low) / 2)) as usize;

                if key == ranked[middle] {
                    return middle as i32;
                }
                else if key > ranked[middle] {
                    return binary_search_descending_order(ranked, low, (middle as i32) - 1, key);
                }
                else {
                    return binary_search_descending_order(ranked, (middle as i32) + 1, high, key);
                }
            }
            return low;
        }

    fn print_result(result: Vec<i32>) {
        for number in result {
            println!("{}", number);
        }
    }
