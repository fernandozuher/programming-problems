// https://www.hackerrank.com/challenges/service-lane/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n_widths: i32 = read!();
    let n_points: i32 = read!();
    let widths: Vec<i32> = read_numbers(n_widths);
    for _ in 0..n_points {
        println!(
            "{}",
            max_affordable_width_vehicle_in_range(&widths, &read_numbers(2))
        )
    }
}

fn read_numbers(n: i32) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn max_affordable_width_vehicle_in_range(widths: &[i32], point: &[i32]) -> i32 {
    let start: usize = point[0] as usize;
    let finish: usize = point[1] as usize;
    *widths[start..=finish].iter().min().unwrap()
}
