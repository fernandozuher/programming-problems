// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

fn main() {
    morfo::skip_input_ln();
    let arr: Vec<i64> = morfo::read_ln();
    println!("{}", a_very_big_sum(&arr));
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
fn a_very_big_sum(arr: &[i64]) -> i64 {
    arr.iter().sum()
}
