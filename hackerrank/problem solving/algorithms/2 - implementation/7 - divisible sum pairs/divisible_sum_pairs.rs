// Source: https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

use std::io::{self, BufRead};

fn main() {
    let input1 = read_line_as_vec_i32();
    let k = input1[1];
    let mut numbers = read_line_as_vec_i32();

    numbers.sort();

    let result = divisible_sum_pairs(&numbers, k);
    println!("{}", result);
}

    fn read_line_as_vec_i32() -> Vec<i32> {
        let stdin = io::stdin();
        
        let numbers: Vec<i32> = stdin.lock()
          .lines().next().unwrap().unwrap()
          .trim().split(' ')
          .map(|s| s.parse().unwrap())
          .collect();

        return numbers;
    }

    fn divisible_sum_pairs(numbers: &Vec<i32>, k: i32) -> i32 {
    	let mut n_divisible_sum_pairs = 0;
        
        for i in 0..(numbers.len() - 1) {
            for j in (i + 1)..numbers.len() {
                if numbers[i] <= numbers[j] && ((numbers[i] + numbers[j]) % k == 0) {
                    n_divisible_sum_pairs += 1;
                }
            }
        }
        
        return n_divisible_sum_pairs;
    }
