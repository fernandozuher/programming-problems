// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: usize = read!();
    let utopian_tree: Vec<i32> = generate_heights_utopian_tree();
    for _ in 0..n {
        let cycles: usize = read!();
        println!("{}", utopian_tree[cycles]);
    }
}

// k: length of output array = 61
// T: O(k) = O(61) = O(1). S: O(61) = O(1) extra space.
fn generate_heights_utopian_tree() -> Vec<i32> {
    const MAX_CYCLES: i32 = 60;
    let mut height = 0;
    (0..=MAX_CYCLES)
        .map(|cycle| {
            height += if is_cycle_happening_during_spring(cycle) {
                height
            } else {
                1
            };
            height
        })
        .collect()
}

fn is_cycle_happening_during_spring(cycle: i32) -> bool {
    cycle & 1 == 1
}
