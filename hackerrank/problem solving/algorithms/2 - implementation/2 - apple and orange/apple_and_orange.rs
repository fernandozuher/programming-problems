// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

use text_io::read;

fn main() {
    let (house, apple_tree, orange_tree) = read_input();
    println!("{}", count_fruits_on_house(&apple_tree, &house));
    println!("{}", count_fruits_on_house(&orange_tree, &house));
}

fn read_input() -> (House, FruitTree, FruitTree) {
    let house_start: i32 = read!();
    let house_end: i32 = read!();
    let apple_tree_location: i32 = read!();
    let orange_tree_location: i32 = read!();
    let n_apples: usize = read!();
    let n_oranges: usize = read!();
    let apple_distances: Vec<i32> = read_numbers(n_apples);
    let orange_distances: Vec<i32> = read_numbers(n_oranges);

    let house = House {
        start: house_start,
        end: house_end,
    };

    let apple_tree = FruitTree {
        tree_location: apple_tree_location,
        fruit_distances: apple_distances,
    };

    let orange_tree = FruitTree {
        tree_location: orange_tree_location,
        fruit_distances: orange_distances,
    };

    (house, apple_tree, orange_tree)
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

struct House {
    start: i32,
    end: i32,
}

impl House {
    fn contains(&self, position: i32) -> bool {
        self.start <= position && position <= self.end
    }
}

struct FruitTree {
    tree_location: i32,
    fruit_distances: Vec<i32>,
}

fn count_fruits_on_house(fruit_tree: &FruitTree, house: &House) -> usize {
    fruit_tree
        .fruit_distances
        .iter()
        .map(|&distance| fruit_tree.tree_location + distance)
        .filter(|&position| house.contains(position))
        .count()
}
