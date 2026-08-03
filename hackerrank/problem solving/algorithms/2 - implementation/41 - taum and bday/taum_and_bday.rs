// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

use std::cmp;

struct Gifts {
    n_black_gifts: i64,
    n_white_gifts: i64,
    black_gift_cost: i64,
    white_gift_cost: i64,
    cost_to_convert_between_gifts: i64,
}

fn main() {
    let n: usize = text_io::read!();
    for _ in 0..n {
        println!("{}", min_cost_of_buying_gifts(read_test_case()));
    }
}

fn read_test_case() -> Gifts {
    Gifts {
        n_black_gifts: text_io::read!(),
        n_white_gifts: text_io::read!(),
        black_gift_cost: text_io::read!(),
        white_gift_cost: text_io::read!(),
        cost_to_convert_between_gifts: text_io::read!(),
    }
}

// T: O(1)
// S: O(1) extra space
fn min_cost_of_buying_gifts(x: Gifts) -> i64 {
    let black_cost = cmp::min(
        x.black_gift_cost,
        x.white_gift_cost + x.cost_to_convert_between_gifts,
    );
    let white_cost = cmp::min(
        x.white_gift_cost,
        x.black_gift_cost + x.cost_to_convert_between_gifts,
    );
    x.n_black_gifts * black_cost + x.n_white_gifts * white_cost
}
