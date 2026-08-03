// https://www.hackerrank.com/challenges/chocolate-feast/problem?isFullScreen=true

fn main() {
    let n: usize = text_io::read!();
    for _ in 0..n {
        let money: i32 = text_io::read!();
        let cost: i32 = text_io::read!();
        let wrappers_needed: i32 = text_io::read!();
        println!(
            "{}",
            how_many_chocolates_can_be_eaten(money, cost, wrappers_needed)
        );
    }
}

// T: O(log(money / cost))
// S: O(1) extra space
fn how_many_chocolates_can_be_eaten(money: i32, cost: i32, wrappers_needed: i32) -> i32 {
    let mut chocolates: i32 = money / cost;
    let mut wrappers: i32 = chocolates;

    while wrappers >= wrappers_needed {
        let free_chocolates: i32 = wrappers / wrappers_needed;
        wrappers = wrappers % wrappers_needed + free_chocolates;
        chocolates += free_chocolates;
    }

    chocolates
}
