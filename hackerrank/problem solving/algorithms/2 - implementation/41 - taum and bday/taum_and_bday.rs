// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

use std::cmp;
use text_io::read;

struct Gifts {
    n_black_gifts: i64,
    n_white_gifts: i64,
    black_gift_cost: i64,
    white_gift_cost: i64,
    cost_to_convert_between_gifts: i64,
}

fn main() {
    let n: usize = read!();
    (0..n).for_each(|_| {
        let test_case = read_test_case();
        println!("{}", min_cost_of_buying_gifts(test_case));
    });
}

fn read_test_case() -> Gifts {
    Gifts {
        n_black_gifts: read!(),
        n_white_gifts: read!(),
        black_gift_cost: read!(),
        white_gift_cost: read!(),
        cost_to_convert_between_gifts: read!(),
    }
}

fn min_cost_of_buying_gifts(x: Gifts) -> i64 {
    let black_cost = cmp::min(
        gifts.black_gift_cost,
        gifts.white_gift_cost + gifts.cost_to_convert_between_gifts,
    );
    let white_cost = cmp::min(
        gifts.white_gift_cost,
        gifts.black_gift_cost + gifts.cost_to_convert_between_gifts,
    );
    gifts.n_black_gifts * black_cost + gifts.n_white_gifts * white_cost
}
