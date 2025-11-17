// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

use text_io::read;

fn main() {
    let days: i32 = read!();
    println!("{}", viral_advertising(days));
}

// n = days = length of the iteration
// T = O(n)
// S = O(1)
fn viral_advertising(days: i32) -> i32 {
    let mut shared = 5;
    (0..days).fold(0, |cumulative, _| {
        let liked = shared / 2;
        shared = liked * 3;
        cumulative + liked
    })
}
