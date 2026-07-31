// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

fn main() {
    const N: usize = 5;
    let arr: Vec<i64> = read_nums(N);
    let (min_sum, max_sum) = calc_min_max_sum(&arr);
    print!("{} {}", min_sum, max_sum);
}

fn read_nums(n: usize) -> Vec<i64> {
    (0..n).map(|_| text_io::read!()).collect()
}

// n: length of arr
// T: O(n)
// S: O(1) extra space
fn calc_min_max_sum(arr: &[i64]) -> (i64, i64) {
    let (mut total, mut min_value, mut max_value) = (arr[0], arr[0], arr[0]);

    arr.iter().skip(1).for_each(|&x| {
        total += x;
        min_value = min_value.min(x);
        max_value = max_value.max(x);
    });

    (total - max_value, total - min_value)
}
