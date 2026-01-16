// https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    for _ in 0..n {
        let n: usize = read!();
        let threshold: i32 = read!();
        let arrival_times: Vec<i32> = read_numbers(n);
        println!("{}", if angry_professor(&arrival_times, threshold) { "YES" } else { "NO" });
    }
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

// k: length of array arrival_times
// T: O(k)
// S: O(1) extra space
fn angry_professor(arrival_times: &[i32], threshold: i32) -> bool {
    let on_time: i32 = arrival_times.iter().filter(|&&t| t <= 0).count() as i32;
    on_time < threshold
}
