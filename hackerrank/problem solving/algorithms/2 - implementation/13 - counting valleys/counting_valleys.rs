// Source: https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true

use std::io::{self, BufRead};

fn main() {
    read_line_as_vec_i32();
    let steps = read_line_as_string();

    let result = counting_valleys(&steps);
    println!("{}", result);
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

    fn read_line_as_string() -> String {
        let mut input_line = String::new();
        let stdin = io::stdin();
        stdin.read_line(&mut input_line);

        return input_line;
    }

    fn counting_valleys(steps: &String) -> i32 {
        let mut current_altitude: i32 = 0;
        let mut traversed_valleys: i32 = 0;

        for step in steps.chars() {
            let mut was_travessing_a_valley: bool = current_altitude < 0;
            current_altitude += if step == 'D' {-1} else {1};
            
            if is_in_sea_level_from_valley(was_travessing_a_valley, current_altitude) {
                traversed_valleys += 1;
            }
        }

        return traversed_valleys;
    }

        fn is_in_sea_level_from_valley(was_travessing_a_valley: bool, current_altitude: i32) -> bool {
            return was_travessing_a_valley && current_altitude == 0;
        }
