// https://www.hackerrank.com/challenges/taum-and-bday/problem?isFullScreen=true

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
    let mut output: Vec<i64> = Vec::new();
    output.resize_with(n, || {
        calculate_minimum_cost_of_buying_gifts(read_test_case())
    });
    output.iter().for_each(|x| println!("{}", x));
}

fn read_test_case() -> Gifts {
    return Gifts {
        n_black_gifts: read!(),
        n_white_gifts: read!(),
        black_gift_cost: read!(),
        white_gift_cost: read!(),
        cost_to_convert_between_gifts: read!(),
    };
}

fn calculate_minimum_cost_of_buying_gifts(x: Gifts) -> i64 {
    match are_original_costs_cheaper_or_equal_than_convertion_between_gifts(&x) {
        true => calculate_minimum_standard_cost(&x),
        false => calculate_minimum_cost_in_converting_gifts(&x),
    }
}

fn are_original_costs_cheaper_or_equal_than_convertion_between_gifts(x: &Gifts) -> bool {
    let cost_to_convert_from_black_to_white: i64 =
        x.black_gift_cost + x.cost_to_convert_between_gifts;
    let cost_to_convert_from_white_to_black: i64 =
        x.white_gift_cost + x.cost_to_convert_between_gifts;

    return x.white_gift_cost <= cost_to_convert_from_black_to_white
        && x.black_gift_cost <= cost_to_convert_from_white_to_black;
}

fn calculate_minimum_standard_cost(x: &Gifts) -> i64 {
    return x.n_black_gifts * x.black_gift_cost + x.n_white_gifts * x.white_gift_cost;
}

fn calculate_minimum_cost_in_converting_gifts(x: &Gifts) -> i64 {
    let cost_to_convert_from_black_to_white: i64 =
        x.black_gift_cost + x.cost_to_convert_between_gifts;
    let total_gifts: i64 = x.n_black_gifts + x.n_white_gifts;

    if x.white_gift_cost > cost_to_convert_from_black_to_white {
        total_gifts * x.black_gift_cost + x.n_white_gifts * x.cost_to_convert_between_gifts
    } else {
        total_gifts * x.white_gift_cost + x.n_black_gifts * x.cost_to_convert_between_gifts
    }
}
