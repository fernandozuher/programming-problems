// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

use std::cmp;
use text_io::read;

fn main() {
    let default_price_game: i32 = read!();
    let discount: i32 = read!();
    let minimum_price_game: i32 = read!();
    let budget: i32 = read!();
    println!(
        "{}",
        how_many_games_can_be_bought(default_price_game, discount, minimum_price_game, budget)
    );
}

fn how_many_games_can_be_bought(
    default_price_game: i32,
    discount: i32,
    minimum_price_game: i32,
    budget: i32,
) -> i32 {
    let mut games_can_be_bought_quantity: i32 = 0;
    let mut current_price_game: i32 = default_price_game;
    let mut current_budget: i32 = budget - default_price_game;

    while current_budget >= 0 {
        games_can_be_bought_quantity += 1;
        current_price_game -= discount;
        current_budget -= cmp::max(current_price_game, minimum_price_game);
    }

    return games_can_be_bought_quantity;
}
