// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

use text_io::read;

fn main() {
    const N: usize = 5;
    let arr: Vec<i64> = read_numbers(N);
    let (min_sum, max_sum) = calc_min_max_sum(&arr);
    print!("{} {}", min_sum, max_sum);
}

fn read_numbers(n: usize) -> Vec<i64> {
    (0..n).map(|_| read!()).collect()
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
fn calc_min_max_sum(arr: &[i64]) -> (i64, i64) {
    let (mut sum, mut min, mut max) = (arr[0], arr[0], arr[0]);

    arr.iter().skip(1).for_each(|x| {
        sum += x;
        min = min.min(*x);
        max = max.max(*x);
    });

    (sum - max, sum - min)
}
