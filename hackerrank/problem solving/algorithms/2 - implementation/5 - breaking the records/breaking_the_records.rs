// Source: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem?isFullScreen=true

use std::io::{self, BufRead};

fn main() {    
    read_line_as_vec_i32();
    let set_a = read_line_as_vec_i32();

    let result = breaking_records(&set_a);
    println!("{} {}", result[0], result[1]);
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

    fn breaking_records(scores: &Vec<i32>) -> Vec<i32> {
    	let (mut most_points, mut breaking_most_points_records) = (scores[0], 0);
    	let (mut least_points, mut breaking_least_points_records) = (scores[0], 0);

        for score in scores {
            if *score > most_points {
                most_points = *score;
                breaking_most_points_records += 1;
            }
            else if *score < least_points {
                least_points = *score;
                breaking_least_points_records += 1;
            }
        }

        let records = vec![breaking_most_points_records, breaking_least_points_records];
        return records;
    }
