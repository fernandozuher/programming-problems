// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

use text_io::read;

fn main() {
    const N: usize = 5;
    let numbers: Vec<i64> = read_numbers(N);
    let (min_sum, max_sum) = calc_min_max_sum(numbers);
    print!("{} {}", min_sum, max_sum);
}

fn read_numbers(n: usize) -> Vec<i64> {
    (0..n).map(|_| read!()).collect()
}

fn calc_min_max_sum(numbers: Vec<i64>) -> (i64, i64) {
    let (mut sum, mut min, mut max) = (numbers[0], numbers[0], numbers[0]);

    numbers.iter().skip(1).for_each(|x| {
        sum += x;
        min = min.min(*x);
        max = max.max(*x);
    });

    (sum - max, sum - min)
}
