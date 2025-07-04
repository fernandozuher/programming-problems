// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

use text_io::read;

fn main() {
    let data: Input = read_input();
    print_output(bon_appetit(&data));
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

fn bon_appetit(data: &Input) -> i32 {
    return data.amount_charged - compute_actual_share(&data.meal_costs, data.item_not_eaten);
}

fn compute_actual_share(meal_costs: &[i32], item_not_eaten: usize) -> i32 {
    let total_cost: i32 = meal_costs.iter().sum();
    let total_shared_cost = total_cost - meal_costs[item_not_eaten];
    total_shared_cost / 2
}

fn print_output(charged: i32) {
    if charged > 0 {
        println!("{}", charged);
    } else {
        println!("Bon Appetit");
    }
}
