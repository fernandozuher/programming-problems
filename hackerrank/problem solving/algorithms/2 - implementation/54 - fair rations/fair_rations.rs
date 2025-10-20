// https://www.hackerrank.com/challenges/fair-rations/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let people_loaf_counts: Vec<i32> = read_numbers(n);
    let min_loaves: i32 = min_loaves_to_satisfy_rules(&people_loaf_counts);
    if min_loaves == -1 {
        println!("NO");
    } else {
        println!("{}", min_loaves);
    }
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn min_loaves_to_satisfy_rules(people_loaf_counts: &[i32]) -> i32 {
    let mut loaves_given: i32 = 0;
    let mut counts: i32 = people_loaf_counts[0];

    people_loaf_counts.iter().skip(1).for_each(|&x| {
        if is_odd(counts) {
            loaves_given += 2;
            counts = x + 1;
        } else {
            counts = x;
        }
    });

    if is_odd(counts) {
        -1
    } else {
        loaves_given
    }
}

fn is_odd(n: i32) -> bool {
    n % 2 == 1
}
