// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

use text_io::read;

fn main() {
    let days: i32 = read!();
    println!("{}", viral_advertising(days));
}

// n: days
// T: O(n)
// S: O(1) extra space
fn viral_advertising(days: i32) -> i32 {
    let mut shared = 5;
    (0..days).fold(0, |acc, _| {
        let liked = shared / 2;
        shared = liked * 3;
        acc + liked
    })
}
