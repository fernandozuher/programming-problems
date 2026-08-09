// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

use morfo::{read, read_n};

struct Input {
    item_not_eaten: usize,
    meal_costs: Vec<i32>,
    amount_charged: i32,
}

fn main() {
    let data: Input = read_input();
    let charged: i32 = bon_appetit(&data);
    if charged > 0 {
        println!("{}", charged);
    } else {
        println!("Bon Appetit");
    }
}

fn read_input() -> Input {
    let n: usize = read();
    Input {
        item_not_eaten: read(),
        meal_costs: read_n(n),
        amount_charged: read(),
    }
}

// n: length of data.meal_costs
// T: O(n)
// S: O(1) extra space
fn bon_appetit(data: &Input) -> i32 {
    let mut total_shared_cost =
        data.meal_costs.iter().sum::<i32>() - data.meal_costs[data.item_not_eaten];
    total_shared_cost /= 2;
    data.amount_charged - total_shared_cost
}
