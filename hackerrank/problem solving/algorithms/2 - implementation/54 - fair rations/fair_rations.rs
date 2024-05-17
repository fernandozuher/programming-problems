// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

use num::Integer;
use text_io::read;

fn main() {
    let n: i32 = read!();
    let min_loaves = find_min_loaves_to_satisfy_rules(n);
    if min_loaves != -1 {
        println!("{}", min_loaves);
    } else {
        println!("NO");
    }
}

fn find_min_loaves_to_satisfy_rules(n: i32) -> i32 {
    let mut min_loaves_to_satisfy_rules: i32 = 0;
    let mut loaves: i32 = read!();

    for _i in 1..n {
        if loaves.is_odd() {
            loaves = read!();
            loaves += 1;
            min_loaves_to_satisfy_rules += 2;
        } else {
            loaves = read!();
        }
    }

    return if loaves.is_odd() {
        -1
    } else {
        min_loaves_to_satisfy_rules
    };
}
