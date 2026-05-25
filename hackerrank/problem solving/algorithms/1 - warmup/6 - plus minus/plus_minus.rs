// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let arr: Vec<i32> = read_numbers(n);
    let ratios: Vec<f32> = plus_minus(&arr);
    print_ratios(ratios);
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
fn plus_minus(arr: &[i32]) -> Vec<f32> {
    let mut positive: i32 = 0;
    let mut negative: i32 = 0;
    let mut zero: i32 = 0;

    for number in arr.iter() {
        if *number > 0 {
            positive += 1;
        } else if *number < 0 {
            negative += 1;
        } else {
            zero += 1;
        }
    }

    let n = arr.len() as f32;
    vec![positive as f32 / n, negative as f32 / n, zero as f32 / n]
}

fn print_ratios(ratios: Vec<f32>) {
    for ratio in ratios.iter() {
        println!("{:.6}", ratio);
    }
}
