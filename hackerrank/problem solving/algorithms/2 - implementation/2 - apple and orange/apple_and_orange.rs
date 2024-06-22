// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

use text_io::read;

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
        let mut input: AppleAndOrange = AppleAndOrange {
            starting_sam: read!(),
            ending_sam: read!(),
            apple_tree_location: read!(),
            orange_tree_location: read!(),
            n_apples: read!(),
            n_oranges: read!(),
            apples_distance_from_tree: vec![],
            oranges_distance_from_tree: vec![],
        };
        input.apples_distance_from_tree = read_int_array(input.n_apples);
        input.oranges_distance_from_tree = read_int_array(input.n_oranges);
        return input;
    }

        fn read_int_array(n: usize) -> Vec<i32> {
            return (0..n).map(|_| read!()).collect();
        }

    fn count_apples_and_oranges(input: &AppleAndOrange) {
        let apples_on_house = count_fruits_on_house(&input, "apple".to_string());
        let oranges_on_house = count_fruits_on_house(&input, "orange".to_string());
        print!("{}\n{}", apples_on_house, oranges_on_house);
    }

        fn count_fruits_on_house(input: &AppleAndOrange, fruit: String) -> i32 {
            let (tree_location, fruits): (i32, Vec<i32>) = filter_input(input, fruit);
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

            fn filter_input(input: &AppleAndOrange, fruit: String) -> (i32, Vec<i32>) {
                if fruit == "apple" {
                    return (input.apple_tree_location, input.apples_distance_from_tree.clone());
                }
                return (input.orange_tree_location, input.oranges_distance_from_tree.clone());
            }
