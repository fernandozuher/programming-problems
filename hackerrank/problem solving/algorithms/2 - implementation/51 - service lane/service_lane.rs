// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

fn main() {
    let n: i32 = text_io::read!();
    let t: i32 = text_io::read!();
    let widths: Vec<i32> = read_nums(n);
    for _ in 0..t {
        println!("{}", min_width_in_segment(&widths, &read_nums(2)))
    }
}

fn read_nums(n: i32) -> Vec<i32> {
    (0..n).map(|_| text_io::read!()).collect()
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
