// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let mut output: Vec<i32> = Vec::new();

    output.resize_with(n, || {
        let amount_of_money: i32 = read!();
        let chocolate_bar_cost: i32 = read!();
        let n_wrappers_to_turn_in_bar: i32 = read!();

        return how_many_chocolates_can_be_eaten(
            amount_of_money,
            chocolate_bar_cost,
            n_wrappers_to_turn_in_bar,
        );
    });

    output.iter().for_each(|x| println!("{}", x));
}

fn how_many_chocolates_can_be_eaten(
    amount_of_money: i32,
    chocolate_bar_cost: i32,
    n_wrappers_to_turn_in_bar: i32,
) -> i32 {
    let mut eaten_chocolates: i32 = amount_of_money / chocolate_bar_cost;
    let mut available_wrappers: i32 = eaten_chocolates;

    while available_wrappers >= n_wrappers_to_turn_in_bar {
        let chocolates_for_free: i32 = available_wrappers / n_wrappers_to_turn_in_bar;
        available_wrappers = available_wrappers - chocolates_for_free * n_wrappers_to_turn_in_bar
            + chocolates_for_free;
        eaten_chocolates += chocolates_for_free;
    }

    return eaten_chocolates;
}
