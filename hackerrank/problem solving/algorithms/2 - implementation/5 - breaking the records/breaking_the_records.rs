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
    	let (mut least_points, mut least_points_count) = (scores[0], 0);
        let (mut most_points, mut most_points_count) = (scores[0], 0);

        for score in scores {
            if *score > most_points {
                most_points = *score;
                most_points_count += 1;
            }
            else if *score < least_points {
                least_points = *score;
                least_points_count += 1;
            }
        }

        let records = vec![most_points_count, least_points_count];
        return records;
    }
