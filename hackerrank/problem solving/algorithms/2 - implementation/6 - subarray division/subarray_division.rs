// Source: https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

use std::io::{self, BufRead};

fn main() {
    read_line_as_vec_i32();
    let chocolate_squares = read_line_as_vec_i32();
    let day_month = read_line_as_vec_i32();

    let result = birthday(&chocolate_squares, &day_month);
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

    fn birthday(chocolate_squares: &Vec<i32>, day_month: &Vec<i32>) -> i32 {
        let mut ways_bar_can_be_divided = 0;
        let day = day_month[0];
        let month = day_month[1] as usize;

        for i in 0..(chocolate_squares.len() - month + 1) {
            let mut sum = 0;
            for j in i..(i + month) {
                sum += chocolate_squares[j];
            }

            if sum == day {
                ways_bar_can_be_divided += 1;
            }
        }
        return ways_bar_can_be_divided;
    }
