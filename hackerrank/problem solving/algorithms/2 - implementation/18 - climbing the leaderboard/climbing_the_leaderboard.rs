// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem?isFullScreen=true

use text_io::read;

fn main() {
    let mut n: usize = read!();
    let mut ranked: Vec<i32> = read_int_array(n);
    ranked.dedup();

    n = read!();
    let player: Vec<i32> = read_int_array(n);
    print_array(&climbing_leaderboard(&ranked, &player));
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn climbing_leaderboard(ranked: &Vec<i32>, player: &Vec<i32>) -> Vec<i32> {
    let mut player_rank: Vec<i32> = vec![0; player.len()];

    let last_index: i32 = (ranked.len() - 1) as i32;
    for i in 0..player.len() {
        let index: i32 = binary_search_descending_order(ranked, 0, last_index, player[i]);
        player_rank[i] = index + 1;
    }

    return player_rank;
}

fn binary_search_descending_order(array: &Vec<i32>, low: i32, high: i32, key: i32) -> i32 {
    if high >= low {
        let middle: usize = (low + ((high - low) / 2)) as usize;

        if key == array[middle] {
            return middle as i32;
        } else if key > array[middle] {
            return binary_search_descending_order(array, low, (middle - 1) as i32, key);
        } else {
            return binary_search_descending_order(array, (middle + 1) as i32, high, key);
        }
    }
    return low;
}

fn print_array(array: &Vec<i32>) {
    for element in array {
        println!("{}", element);
    }
}
