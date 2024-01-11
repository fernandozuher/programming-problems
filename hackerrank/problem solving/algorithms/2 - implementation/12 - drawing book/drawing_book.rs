// https://www.hackerrank.com/challenges/drawing-book/problem?isFullScreen=true

use std::cmp;
use text_io::read;

fn main() {
    let page_quantity: i32 = read!();
    let page: i32 = read!();
    println!("{}", page_count(page_quantity, page));
}

fn page_count(page_quantity: i32, page: i32) -> i32 {
    let turn_of_pages_from_front: i32 = calculate_turn_of_pages(page);
    let maximum_turns: i32 = calculate_turn_of_pages(page_quantity);
    let turn_of_pages_from_back: i32 = maximum_turns - turn_of_pages_from_front;
    let minimum_turn_of_pages: i32 = cmp::min(turn_of_pages_from_front, turn_of_pages_from_back);
    return minimum_turn_of_pages;
}

fn calculate_turn_of_pages(page: i32) -> i32 {
    return if page & 1 == 1 {
        page_is_odd(page)
    } else {
        page_is_even(page)
    };
}

fn page_is_odd(page: i32) -> i32 {
    return (page - 1) / 2;
}

fn page_is_even(page: i32) -> i32 {
    return page / 2;
}
