// https://www.hackerrank.com/challenges/minimum-distances/problem?isFullScreen=true

use morfo::{read_ln, skip_input_ln};
use std::collections::HashMap;

fn main() {
    skip_input_ln();
    let arr: Vec<i32> = read_ln();
    println!("{}", min_distance(&arr));
}

// n: length of arr
// T: O(n)
// S: O(n) extra space
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
