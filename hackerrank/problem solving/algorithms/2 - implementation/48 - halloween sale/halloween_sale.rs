// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

use std::cmp::max;
use text_io::read;

fn main() {
    let price: i32 = read!();
    let discount: i32 = read!();
    let min_price: i32 = read!();
    let budget: i32 = read!();
    println!(
        "{}",
        how_many_games_can_be_bought(price, discount, min_price, budget)
    );
}

fn how_many_games_can_be_bought(
    mut price: i32,
    discount: i32,
    min_price: i32,
    mut budget: i32,
) -> usize {
    let mut count: usize = 0;
    while budget >= price {
        count += 1;
        budget -= price;
        price = max(price - discount, min_price);
    }
    count
}
