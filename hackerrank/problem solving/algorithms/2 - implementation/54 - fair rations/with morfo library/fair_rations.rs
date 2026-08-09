// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

use morfo::{read_ln, skip_input_ln};
use num::Integer;

fn main() {
    skip_input_ln();
    let people_loaf_counts: Vec<i32> = read_ln();
    let min_loaves: i32 = min_loaves_to_satisfy_rules(&people_loaf_counts);
    if min_loaves == -1 {
        println!("NO");
    } else {
        println!("{}", min_loaves);
    }
}

// n: length of people_loaf_counts
// T: O(n)
// S: O(1) extra space
fn min_loaves_to_satisfy_rules(people_loaf_counts: &[i32]) -> i32 {
    let mut loaves_given: i32 = 0;
    let mut counts: i32 = people_loaf_counts[0];

    people_loaf_counts.iter().skip(1).for_each(|&x| {
        if counts.is_odd() {
            loaves_given += 2;
            counts = x + 1;
        } else {
            counts = x;
        }
    });

    if counts.is_odd() {
        -1
    } else {
        loaves_given
    }
}
