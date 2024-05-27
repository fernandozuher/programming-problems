// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let (positive_proportion, negative_proportion, zero_proportion) = plus_minus(n);
    println!("{:.6}", positive_proportion);
    println!("{:.6}", negative_proportion);
    println!("{:.6}", zero_proportion);
}

fn plus_minus(n: usize) -> (f32, f32, f32) {
    let mut positive: i32 = 0;
    let mut negative: i32 = 0;
    let mut zero: i32 = 0;

    for _ in 0..n {
        let x: i32 = read!();
        if x > 0 {
            positive += 1;
        } else if x < 0 {
            negative += 1;
        } else {
            zero += 1;
        }
    }

    let positive_proportion = positive as f32 / n as f32;
    let negative_proportion = negative as f32 / n as f32;
    let zero_proportion = zero as f32 / n as f32;
    return (positive_proportion, negative_proportion, zero_proportion);
}
