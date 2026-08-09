// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

use morfo::{read, read_ln, skip_input};

fn main() {
    let n: usize = read();
    for _ in 0..n {
        skip_input();
        let threshold: i32 = read();
        let arrival_times: Vec<i32> = read_ln();
        println!("{}", if angry_professor(&arrival_times, threshold) { "YES" } else { "NO" });
    }
}

// k: length of arrival_times
// T: O(k)
// S: O(1) extra space
fn angry_professor(arrival_times: &[i32], threshold: i32) -> bool {
    let on_time: i32 = arrival_times.iter().filter(|&&t| t <= 0).count() as i32;
    on_time < threshold
}
