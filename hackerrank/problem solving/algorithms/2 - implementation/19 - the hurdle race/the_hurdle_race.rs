// https://www.hackerrank.com/challenges/the-hurdle-race/problem?isFullScreen=true

fn main() {
    let n: usize = text_io::read!();
    let max_jump: i32 = text_io::read!();
    let hurdles = read_nums(n);
    println!("{}", hurdle_race(&hurdles, max_jump));
}

fn read_nums(n: usize) -> Vec<i32> {
    (0..n).map(|_| text_io::read!()).collect()
}

// n: length of hurdles
// T: O(n)
// S: O(1) extra space
fn hurdle_race(hurdles: &[i32], max_jump: i32) -> i32 {
    0.max(*hurdles.iter().max().unwrap() - max_jump)
}
