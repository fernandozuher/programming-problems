// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

use morfo::read_ln;

fn main() {
    let nt: Vec<i32> = read_ln();
    let t = nt[1];
    let widths: Vec<i32> = read_ln();
    for _ in 0..t {
        let segment: Vec<i32> = read_ln();
        println!("{}", min_width_in_segment(&widths, &segment))
    }
}

// n: length of widths
// T: O(n)
// S: O(1) extra space
fn min_width_in_segment(widths: &[i32], segment: &[i32]) -> i32 {
    let start = segment[0] as usize;
    let finish = segment[1] as usize;
    *widths[start..=finish]
        .iter()
        .min()
        .unwrap()
}
