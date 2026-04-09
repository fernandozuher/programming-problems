// https://www.hackerrank.com/challenges/halloween-sale/problem?isFullScreen=true

use std::cmp::max;
use text_io::scan;

fn main() {
    let (price, discount, min_price, budget): (i32, i32, i32, i32);
    scan!("{} {} {} {}", price, discount, min_price, budget);
    println!(
        "{}",
        how_many_games_can_be_bought(price, discount, min_price, budget)
    );
}

// T: O(budget / min_price)
// S: O(1) extra space
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
