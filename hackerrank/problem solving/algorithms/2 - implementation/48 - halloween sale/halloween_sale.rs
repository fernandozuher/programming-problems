// Source: https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

use std::convert::TryFrom;
use std::io::{stdin, BufRead};

fn main() {
    let [game_default_price, discount, game_minimum_price, budget] =
        <[i32; 4]>::try_from(read_an_int_array()).ok().unwrap();

    println!(
        "{}",
        how_many_games_can_be_bought(game_default_price, discount, game_minimum_price, budget)
    );
}

fn read_an_int_array() -> Vec<i32> {
    let array: Vec<i32> = stdin()
        .lock()
        .lines()
        .next()
        .unwrap()
        .unwrap()
        .trim()
        .split(' ')
        .map(|s| s.parse().unwrap())
        .collect();

    return array;
}

fn how_many_games_can_be_bought(
    game_default_price: i32,
    discount: i32,
    game_minimum_price: i32,
    budget: i32,
) -> i32 {
    let mut games_can_be_bought_quantity: i32 = 0;
    let mut current_game_price: i32 = game_default_price;
    let mut current_budget: i32 = budget - game_default_price;

    while current_budget >= 0 {
        games_can_be_bought_quantity += 1;
        current_game_price -= discount;

        current_budget -= if current_game_price >= game_minimum_price {
            current_game_price
        } else {
            game_minimum_price
        };
    }

    return games_can_be_bought_quantity;
}
