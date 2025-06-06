// https://www.hackerrank.com/challenges/30-review-loop/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: i32 = read!();

    for _ in 0..n {
        let word: String = read!();
        let (mut word1, mut word2) = (String::new(), String::new());
        let mut is_word1_turn = true;

        for ch in word.chars() {
            if is_word1_turn {
                word1.push(ch)
            } else {
                word2.push(ch)
            }
            is_word1_turn = !is_word1_turn;
        }

        println!("{} {}", word1, word2);
    }
}
