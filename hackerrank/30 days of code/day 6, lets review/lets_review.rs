// https://www.hackerrank.com/challenges/30-review-loop/problem?isFullScreen=true

use text_io::read;

fn main() {
    let n: i32 = read!();

    for _ in 0..n {
        let word: String = read!();
        let (mut word1, mut word2) = (String::new(), String::new());
        let mut isWord1Turn = true;

        for ch in word.chars() {
            if isWord1Turn {
                word1.push(ch)
            } else {
                word2.push(ch)
            }
            isWord1Turn = !isWord1Turn;
        }

        println!("{} {}", word1, word2);
    }
}
