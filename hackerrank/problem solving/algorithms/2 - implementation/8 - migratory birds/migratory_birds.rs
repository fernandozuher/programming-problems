// Source: https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

use std::io::{self, BufRead};

fn main() {
    read_line_as_vec_i32();
    let mut bird_sightings = read_line_as_vec_i32();

    bird_sightings.sort();

    let result = migratory_birds(&bird_sightings);
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

    fn migratory_birds(bird_sightings: &Vec<i32>) -> i32 {
        let mut most_spotted_bird = *bird_sightings.first().unwrap();
        let mut count_most_spotted_bird = 1;
        let mut temp_count_most_spotted_bird = 1;

        for i in 1..bird_sightings.len() {
            if bird_sightings[i] == bird_sightings[i - 1] {
                temp_count_most_spotted_bird += 1;
            }
            else if temp_count_most_spotted_bird > count_most_spotted_bird {
                most_spotted_bird = bird_sightings[i - 1];
                count_most_spotted_bird = temp_count_most_spotted_bird;
                temp_count_most_spotted_bird = 1;
            }
        }

        if temp_count_most_spotted_bird > count_most_spotted_bird {
            most_spotted_bird = *bird_sightings.last().unwrap();
        }

        return most_spotted_bird;
    }
