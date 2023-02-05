// Source: https://www.hackerrank.com/challenges/strange-advertising/problem?isFullScreen=true

#[macro_use]
extern crate text_io;
    
fn main() {
    let days: i32 = read!();
    let cumulative_likes: i32 = viral_advertising(days);
    println!("{}", cumulative_likes);
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
