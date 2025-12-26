// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: i32 = read!();
    let t: i32 = read!();
    let widths: Vec<i32> = read_numbers(n);
    for _ in 0..t {
        println!("{}", min_width_in_segment(&widths, &read_numbers(2)))
    }
}

fn read_numbers(n: i32) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn min_width_in_segment(widths: &[i32], segment: &[i32]) -> i32 {
    *widths[segment[0] as usize..=segment[1] as usize]
        .iter()
        .min()
        .unwrap()
}
