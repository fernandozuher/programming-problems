// https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

use text_io::read;

fn main() {
    let days: i32 = read!();
    println!("{}", viral_advertising(days));
}

fn viral_advertising(days: i32) -> i32 {
    let (mut shared, mut liked, mut cumulative) = (5, 0, 0);

    for _ in 0..days {
        liked = shared / 2;
        cumulative += liked;
        shared = liked * 3;
    }

    return cumulative;
}
