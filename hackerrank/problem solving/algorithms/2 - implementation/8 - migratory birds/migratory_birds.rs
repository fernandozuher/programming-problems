// https://www.hackerrank.com/challenges/migratory-birds/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut array = read_int_array(n);
    array.sort();

    println!("{}", find_most_spotted_bird(&array));
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn find_most_spotted_bird(bird_sightings: &Vec<i32>) -> i32 {
    let mut most_spotted_bird = *bird_sightings.first().unwrap();
    let mut count_most_spotted_bird = 1;
    let mut temp_count_most_spotted_bird = 1;

    for i in 1..bird_sightings.len() {
        if bird_sightings[i] == bird_sightings[i - 1] {
            temp_count_most_spotted_bird += 1;
        } else if temp_count_most_spotted_bird > count_most_spotted_bird {
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
