// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

use text_io::read;

fn main() {
    let (n, k): (usize, i32) = (read!(), read!());
    let mut array = read_int_array(n);
    array.sort();
    println!("{}", divisible_sum_pairs(&array, k));
}

    fn read_int_array(n: usize) -> Vec<i32> {
        return (0..n).map(|_| read!()).collect();
    }

    fn divisible_sum_pairs(array: &[i32], k: i32) -> i32 {
        let mut n_divisible_sum_pairs = 0;

        for (i, num1) in array.split_last().unwrap().1.iter().enumerate() {
            for num2 in array.iter().skip(i + 1) {
                if num1 <= num2 && ((num1 + num2) % k == 0) {
                    n_divisible_sum_pairs += 1;
                }
            }
        }

        return n_divisible_sum_pairs;
    }
