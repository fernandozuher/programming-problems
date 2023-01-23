// Source: https://www.hackerrank.com/challenges/angry-professor/problem?isFullScreen=true

use std::io::{self, BufRead};


fn main() {
    let input_line: Vec<i32> = read_line_as_vec_i32();
    let n_test_cases: usize = *input_line.first().unwrap() as usize;

    let mut results: Vec<bool> = Vec::with_capacity(n_test_cases);
    unsafe { results.set_len(n_test_cases); }

    for result in results.iter_mut() {
        *result = angry_professor();
    }

    for result in results {
        println!("{}", if result {"YES"} else {"NO"});
    }
}

    fn read_line_as_vec_i32() -> Vec<i32> {
        let stdin = io::stdin();

        let input_line: Vec<i32> = stdin.lock()
          .lines().next().unwrap().unwrap()
          .trim().split(' ')
          .map(|s| s.parse().unwrap())
          .collect();

        return input_line;
    }

    fn angry_professor() -> bool {
        let input_line = read_line_as_vec_i32();
        let cancellation_threshold: i32 = *input_line.last().unwrap();
        let cancelled_class: bool = count_early_arrival_time() < cancellation_threshold;
        return cancelled_class;
    }

        fn count_early_arrival_time() -> i32 {
            let mut early_arrival_time_count: i32 = 0;
            let students_arrival_time: Vec<i32> = read_line_as_vec_i32();

            for student_arrival_time in students_arrival_time.iter() {
                if *student_arrival_time <= 0 {
                    early_arrival_time_count += 1;
                }
            }

            return early_arrival_time_count;
        }
