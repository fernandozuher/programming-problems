// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

fn main() {
    let n: usize = text_io::read!();
    let arr: Vec<i64> = read_nums(n);
    println!("{}", a_very_big_sum(&arr));
}

fn read_nums(n: usize) -> Vec<i64> {
    (0..n).map(|_| text_io::read!()).collect()
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
fn a_very_big_sum(arr: &[i64]) -> i64 {
    arr.iter().sum()
}
