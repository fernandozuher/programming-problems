// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

use std::collections::HashMap;
use text_io::read;

fn main() {
    let n: usize = read!();
    let arr: Vec<i32> = read_numbers(n);
    println!("{}", min_distance(&arr));
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn min_distance(arr: &[i32]) -> i32 {
    let mut last_seen: HashMap<i32, i32> = HashMap::new();
    let mut min_dist: i32 = -1;

    for (i, x) in arr.iter().enumerate() {
        if last_seen.contains_key(x) {
            let dist: i32 = i as i32 - last_seen[x];
            if min_dist == -1 || dist < min_dist {
                min_dist = dist;
                if min_dist == 1 {
                    return 1;
                }
            }
        }
        last_seen.insert(*x, i as i32);
    }

    min_dist
}
