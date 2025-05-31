// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

use text_io::read;

fn main() {
    let (house, apples, oranges) = read_input();
    println!("{}", count_fruits_on_house(&apples, &house));
    println!("{}", count_fruits_on_house(&oranges, &house));
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

    let apple = FruitTree {
        tree_location: apple_tree_location,
        fruit_distances: apple_distances,
    };

    let orange = FruitTree {
        tree_location: orange_tree_location,
        fruit_distances: orange_distances,
    };

    (house, apple, orange)
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

fn count_fruits_on_house(fruit: &FruitTree, house: &House) -> usize {
    fruit
        .fruit_distances
        .iter()
        .map(|&distance| fruit.tree_location + distance)
        .filter(|&position| house.contains(position))
        .count()
}
