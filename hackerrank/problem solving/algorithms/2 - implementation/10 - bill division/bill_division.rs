// https://www.hackerrank.com/challenges/bon-appetit/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let item_anna_didnt_consume: i32 = read!();
    let cost_of_each_meal = read_int_array(n);
    let brian_charged_anna = read!();

    let brian_overcharged_ana = bon_appetit(
        &cost_of_each_meal,
        item_anna_didnt_consume,
        brian_charged_anna,
    );
    print_output(brian_overcharged_ana);
}

fn read_int_array(n: usize) -> Vec<i32> {
    let mut array: Vec<i32> = Vec::new();
    array.resize_with(n, || read!());
    return array;
}

fn bon_appetit(
    cost_of_each_meal: &Vec<i32>,
    item_anna_didnt_consume: i32,
    brian_charged_anna: i32,
) -> i32 {
    let anna_cost = calculate_anna_cost(cost_of_each_meal, item_anna_didnt_consume);
    return calculate_how_much_brian_overcharged_anna(brian_charged_anna, anna_cost);
}

fn calculate_anna_cost(cost_of_each_meal: &Vec<i32>, item_anna_didnt_consume: i32) -> i32 {
    let sum: i32 = cost_of_each_meal.iter().sum();
    let anna_cost: i32 = (sum - cost_of_each_meal[item_anna_didnt_consume as usize]) / 2;
    return anna_cost;
}

fn calculate_how_much_brian_overcharged_anna(mut brian_charged_anna: i32, anna_cost: i32) -> i32 {
    if anna_cost != brian_charged_anna {
        return brian_charged_anna - anna_cost;
    }
    return 0;
}

fn print_output(charged: i32) {
    if charged > 0 {
        println!("{}", charged);
    } else {
        println!("Bon Appetit");
    }
}
