// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

use text_io::read;

fn main() {
    let data: Input = read_input();
    let charged: i32 = bon_appetit(&data);
    if charged > 0 {
        println!("{}", charged);
    } else {
        println!("Bon Appetit");
    }
}

struct Input {
    item_not_eaten: usize,
    meal_costs: Vec<i32>,
    amount_charged: i32,
}

fn read_input() -> Input {
    let n: usize = read!();
    Input {
        item_not_eaten: read!(),
        meal_costs: read_numbers(n),
        amount_charged: read!(),
    }
}

fn read_numbers(n: usize) -> Vec<i32> {
    (0..n).map(|_| read!()).collect()
}

// n: length of array data.meal_costs
// T: O(n)
// S: O(1) extra space
fn bon_appetit(data: &Input) -> i32 {
    let mut total_shared_cost =
        data.meal_costs.iter().sum::<i32>() - data.meal_costs[data.item_not_eaten];
    total_shared_cost /= 2;
    data.amount_charged - total_shared_cost
}
