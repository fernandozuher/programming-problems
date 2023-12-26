// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

use text_io::{read, scan};

fn main() {
    let input: AppleAndOrange = read_input();
    count_apples_and_oranges(&input);
}

struct AppleAndOrange {
    starting_sam: i32,
    ending_sam: i32,
    apple_tree_location: i32,
    orange_tree_location: i32,
    n_apples: usize,
    n_oranges: usize,
    apples_distance_from_tree: Vec<i32>,
    oranges_distance_from_tree: Vec<i32>,
}

fn read_input() -> AppleAndOrange {
    let (starting_sam, ending_sam): (i32, i32);
    scan!("{} {}", starting_sam, ending_sam);

    let (apple_tree_location, orange_tree_location): (i32, i32);
    scan!("{} {}", apple_tree_location, orange_tree_location);

    let (n_apples, n_oranges): (usize, usize);
    scan!("{} {}", n_apples, n_oranges);

    let apples_distance_from_tree: Vec<i32> = read_int_array(n_apples);
    let oranges_distance_from_tree: Vec<i32> = read_int_array(n_oranges);

    return AppleAndOrange {
        starting_sam,
        ending_sam,
        apple_tree_location,
        orange_tree_location,
        n_apples,
        n_oranges,
        apples_distance_from_tree,
        oranges_distance_from_tree,
    };
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn count_apples_and_oranges(input: &AppleAndOrange) {
    let apples_on_house = count_fruits_on_house(&input, "apple".to_string());
    let oranges_on_house = count_fruits_on_house(&input, "orange".to_string());
    print!("{}\n{}", apples_on_house, oranges_on_house);
}

fn count_fruits_on_house(input: &AppleAndOrange, fruit: String) -> i32 {
    let filtered_input: Vec<Vec<i32>> = filter_input(input, fruit);
    let tree_location: i32 = *filtered_input.first().unwrap().first().unwrap();
    let fruits: &Vec<i32> = &filtered_input[1];

    let verify_fruit_location =
        |input: &AppleAndOrange, tree_location: i32, partial_location: i32| -> bool {
            let location = tree_location + partial_location;
            return location >= input.starting_sam && location <= input.ending_sam;
        };

    let filtered_fruits_iterator = fruits
        .iter()
        .filter(|&&partial_location| verify_fruit_location(input, tree_location, partial_location));

    let filtered_fruits_container = filtered_fruits_iterator.cloned().collect::<Vec<i32>>();

    return filtered_fruits_container.len() as i32;
}

fn filter_input(input: &AppleAndOrange, fruit: String) -> Vec<Vec<i32>> {
    const data: i32 = 2;
    let mut filtered_input: Vec<Vec<i32>> = vec![vec![0], Vec::new()];

    if fruit == "apple" {
        filtered_input[0][0] = input.apple_tree_location;
        filtered_input[1] = input.apples_distance_from_tree.clone();
    } else {
        filtered_input[0][0] = input.orange_tree_location;
        filtered_input[1] = input.oranges_distance_from_tree.clone();
    }

    return filtered_input;
}
